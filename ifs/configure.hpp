
#ifndef FS_CONFIGURE_H
#define FS_CONFIGURE_H

// To enabled logging with info level
#define LOG_INFO
//#define LOG_DEBUG
//#define LOG_TRACE
#define LOG_DAEMON_PATH "/tmp/adafs_daemon.log"

// Enable logging for daemon
#define LOG_PRELOAD_INFO
//#define LOG_PRELOAD_DEBUG
//#define LOG_PRELOAD_TRACE
#define LOG_PRELOAD_PATH "/tmp/adafs_preload.log"

// If ACM time should be considered
#define ACMtime //unused
#define BLOCKSIZE 4 // in kilobytes
#define CHUNKSIZE 400 // in bytes

// What metadata is used TODO this has to be parametrized or put into a configuration file
#define MDATA_USE_ATIME false
#define MDATA_USE_MTIME false
#define MDATA_USE_CTIME false
#define MDATA_USE_UID false
#define MDATA_USE_GID false
#define MDATA_USE_INODE_NO false
#define MDATA_USE_LINK_CNT false
#define MDATA_USE_BLOCKS false
#define MDATA_USE_SIZE true // XXX to be added in ADAFS_DATA. currently on by default

// should permissions be checked when access() is called or discarded
//#define CHECK_ACCESS
// If access permissions should be checked while opening a file
//#define CHECK_ACCESS_DURING_OPEN
// If disabled, a file or directory is always presumed to be there (even if it is not). No check is executed
#define DO_LOOKUP

// Write-ahead logging of rocksdb
//#define RDB_WOL

// RPC configuration
#define RPCPORT 4433
#define RPC_TRIES 3
#define RPC_TIMEOUT 150000
// Set a hostname suffix when a connection is built. E.g., "-ib" to use Infiniband
#define HOSTNAME_SUFFIX ""
//#define MARGODIAG // enables diagnostics of margo (printed after shutting down

// Debug configurations
//#define RPC_TEST //unused

#endif //FS_CONFIGURE_H
