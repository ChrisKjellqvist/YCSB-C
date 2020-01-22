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
#include <pku_memcached.h>

// KVPair is std::pair<std::string, std::string>

namespace ycsbc {

class TCDDB : public DB {
 public:
  void Init() {
    memcached_init(0);
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

