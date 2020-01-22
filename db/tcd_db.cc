//
//  basic_db.h
//  YCSB-C
//
//  Created by Jinglei Ren on 12/17/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//
#include "tcd_db.h"
#include <utility>
#include <assert.h>
#include <iostream>

// WARNING: we only consider 1 field. Workloads should be cooked such that they
// only give us 1 field!!!
namespace ycsbc {
  int TCDDB::Read(const std::string &table, const std::string &key,
      const std::vector<std::string> *fields,
      std::vector<KVPair> &result) {
    std::string keystr = table + key;
    size_t v_len;
    uint32_t flags;
    memcached_return_t err;
    char *cstr =  memcached_get_internal(
        key.c_str(), key.size(),
        &v_len, &flags, &err); 
    if (err == MEMCACHED_SUCCESS)
      result.push_back(std::make_pair(std::string("field0"), std::string(cstr, v_len))); 
    return DB::kOK;
  }

  int TCDDB::Scan(const std::string &table, const std::string &key,
      int len, const std::vector<std::string> *fields,
      std::vector<std::vector<KVPair>> &result) {
    assert(0 && "This is not implemented");
    return 0;
  }

  int TCDDB::Update(const std::string &table, const std::string &key,
      std::vector<KVPair> &values) {
    std::string keystr = table + key;
    std::string field, value; 
    std::tie(field, value) = values[0]; 
    assert(field == "field0");
    size_t v_len;
    uint32_t flags;
    const char *val_str = value.c_str();
    memcached_return_t err = memcached_set_internal(
        keystr.c_str(), keystr.size(),
        val_str, value.size(), 
        0, 0);
  if (err != MEMCACHED_SUCCESS)
    fprintf(stderr, "We didn't insert correctly...\n");
  return DB::kOK;

}

int TCDDB::Insert(const std::string &table, const std::string &key,
    std::vector<KVPair> &values) {
  return Update(table, key, values); 
}

int TCDDB::Delete(const std::string &table, const std::string &key){
  assert(0 && "This is not implemented");
}

};

