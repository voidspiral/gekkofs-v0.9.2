//
// Created by lefthy on 1/24/17.
//

#ifndef MAIN_H
#define MAIN_H

#define FUSE_USE_VERSION 30

extern "C" {
    #include <fuse3/fuse_lowlevel.h>
}
// std libs
#include <string>
#include <iostream>
#include <cstdint>
#include <unordered_map>

// boost libs
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
// adafs
#include "configure.hpp"
// third party libs
#include "spdlog/spdlog.h"
#include "spdlog/fmt/fmt.h"
// rocksdb
#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/options.h>
#include <rocksdb/utilities/transaction.h>
#include <rocksdb/utilities/optimistic_transaction_db.h>
// margo
extern "C" {
#include <abt.h>
#include <abt-snoozer.h>
#include <abt-io.h>
#include <margo.h>
}

// classes
#include "classes/fs_data.hpp"
#include "classes/rpc_data.hpp"

namespace bfs = boost::filesystem;

#define ADAFS_ROOT_INODE static_cast<fuse_ino_t>(1)
#define INVALID_INODE static_cast<fuse_ino_t>(0)
#define ADAFS_DATA (static_cast<FsData*>(FsData::getInstance()))
#define RPC_DATA (static_cast<RPCData*>(RPCData::getInstance()))

namespace Util {
    int init_inode_no();

    fuse_ino_t generate_inode_no();

    int read_inode_cnt();

    int write_inode_cnt();
}

#endif //MAIN_H
