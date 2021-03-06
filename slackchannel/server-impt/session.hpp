#ifndef __SLACKCHANNEL_SESSION_HPP__
#define __SLACKCHANNEL_SESSION_HPP__

#include "server-impt.hpp"
#include "common-impt/reader.hpp"

namespace SlackChannel
{
    class Session : public boost::enable_shared_from_this<Session>
    {
        public:

            Session( boost::asio::io_service& io_service );
            ~Session();

            void gear( void );
            boost::asio::ip::tcp::socket& get_socket();

        private:

            void incomming( const char* buffer, size_t len );

            Reader* m_reader_ptr;
            boost::asio::ip::tcp::socket m_socket;
    };

    using SessionPtr = boost::shared_ptr<Session>;
}

#endif /*  __SLACKCHANNEL_SESSION_HPP__ */
