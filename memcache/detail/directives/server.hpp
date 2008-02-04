
// Copyright 2007, 2008 (c) Friendster, Inc.
// Copyright 2007, 2008 (c) Dean Michael Berris <dmberris@friendster.com>
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef __MEMCACHE_DETAIL_DIRECTIVES_SERVER_HPP__
#define __MEMCACHE_DETAIL_DIRECTIVES_SERVER_HPP__

#include "../tags.hpp"
#include <string>

namespace memcache { namespace detail {

        template <typename tag>
        struct server_directive {
            explicit server_directive(std::string const & name, std::string const & port) : _server_name(name), _port(port) { };

            template <typename T>
            void operator() (T & handle) const {
                typename T::server_info s_info 
                    = { false, _server_name, _port };
                
                typename T::pool_info p_info 
                    = { 0, typename T::pool_info::member_container() };

                handle.add_server((_server_name + ':') + _port, s_info);
                handle.add_pool((_server_name + ':') + _port, p_info);
            };

            std::string _server_name, _port;
        };

}; // namespace detail

}; // namespace memcache

#endif // __MEMCACHE_DETAIL_DIRECTIVES_SERVER_HPP__

