//
//  basic_db.h
//  YCSB-C
//
//  Created by Jinglei Ren on 12/17/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//

#ifndef YCSB_C_TCD_DB_H_
#define YCSB_C_TCD_DB_H_

#include "core/db.h"
#include <string>
#include "core/properties.h"

#ifdef TCD
#include <pku_memcached.h>
#else
#include "/u/ckjellqv/lmcd/libmemcached/memcached.h"
#endif

// KVPair is std::pair<std::string, std::string>


namespace ycsbc {

#ifdef MCD
static memcached_st st;
static bool has_run = 0;
#endif

class TCDDB : public DB {
 public:
  void Init() {
#ifdef TCD
    memcached_init(0);
#else
    if (!has_run)
      has_run = 1;
    else
      return;
    memcached_create(&st);
    memcached_server_add(&st, "localhost", 11211);
#endif
  }

  int Read(const std::string &table, const std::string &key,
           const std::vector<std::string> *fields,
           std::vector<KVPair> &result);

  int Scan(const std::string &table, const std::string &key,
           int len, const std::vector<std::string> *fields,
           std::vector<std::vector<KVPair>> &result);

  int Update(const std::string &table, const std::string &key,
             std::vector<KVPair> &values);

  int Insert(const std::string &table, const std::string &key,
             std::vector<KVPair> &values);

  int Delete(const std::string &table, const std::string &key);
};

} // ycsbc

#endif // YCSB_C_TCD_DB_H_

