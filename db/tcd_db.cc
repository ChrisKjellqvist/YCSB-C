//
//  basic_db.h
//  YCSB-C
//
//  Created by Jinglei Ren on 12/17/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//
#include "tcd_db.h"

namespace ycsbc {
  
  // each kv pair will be stored as ((table,key,field), (value))

int tcd_DB::Read(const std::string &table, const std::string &key,
         const std::vector<std::string> *fields,
         std::vector<KVPair> &result) {
  std::string keystr = table + key;
  for(auto field: fields){
    std::string key = keystr+field;
    size_t v_len;
    uint32_t flags;
    memcached_return_t err;
    char *cstr =  memcached_get_internal(
          key, key.size(),
          &v_len, &flags, &err); 
    if (cstr != nullptr)
        result.push_back(std::make_pair(field, std::string(cstr, v_len))); 
  } 
  return DB::kOK;
}

int tcd_DB::Scan(const std::string &table, const std::string &key,
         int len, const std::vector<std::string> *fields,
         std::vector<std::vector<KVPair>> &result);

int tcd_DB::Update(const std::string &table, const std::string &key,
           std::vector<KVPair> &values);

int tcd_DB::Insert(const std::string &table, const std::string &key,
           std::vector<KVPair> &values);

int tcd_DB::Delete(const std::string &table, const std::string &key);

};

} // ycsbc
