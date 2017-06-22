//
// Created by evie on 6/21/17.
//

#ifndef LFS_RPC_DATA_HPP
#define LFS_RPC_DATA_HPP

#include "../main.hpp"

class RPCData {

private:
    RPCData() {}

    // Can't use shared pointers here 'cause the Mercury environment has problems with it, e.g., unable to finalize,
    // resulting into a faulty fuse shutdown
    // Mercury Server
    hg_class_t* server_hg_class_;
    hg_context_t* server_hg_context_;

    // Mercury Client
    hg_class_t* client_hg_class_;
    hg_context_t* client_hg_context_;

    // Margo IDs. They can also be used to retrieve the Mercury classes and contexts that were created at init time
    margo_instance_id server_mid_;
    margo_instance_id client_mid_;

    // TODO RPC client IDs
    // RPC client IDs
    hg_id_t rpc_minimal_id_;

public:
    static RPCData* getInstance() {
        static RPCData instance;
        return &instance;
    }

    RPCData(RPCData const&) = delete;

    void operator=(RPCData const&) = delete;

    hg_class_t* server_hg_class() const;

    void server_hg_class(hg_class_t* server_hg_class);

    hg_context_t* server_hg_context() const;

    void server_hg_context(hg_context_t* server_hg_context);

    hg_class_t* client_hg_class() const;

    void client_hg_class(hg_class_t* client_hg_class);

    hg_context_t* client_hg_context() const;

    void client_hg_context(hg_context_t* client_hg_context);

    margo_instance* server_mid();

    void server_mid(margo_instance* server_mid);

    margo_instance* client_mid();

    void client_mid(margo_instance* client_mid);

    hg_id_t rpc_minimal_id() const;

    void rpc_minimal_id(hg_id_t rpc_minimal_id);
};


#endif //LFS_RPC_DATA_HPP
