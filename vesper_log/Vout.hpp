/**
 * \file
 * \authors Simon Michalke, Max Mertens
 *
 * Copyright (c) 2014, Max Mertens. All rights reserved.
 * This file is licensed under the "BSD 3-Clause License".
 * Full license text is under the file "LICENSE" provided with this code.
 */

#ifndef VOUT_HPP_INCLUDED
#define VOUT_HPP_INCLUDED

#include <condition_variable>
#include <thread>
#include <mutex>

#include <queue>
#include <sstream>
#include <string>

#include "LoggingTypes.hpp"

namespace Vesper {

class Logging;
class LoggingMessage;

class Vout {

    public:
        static void pushMessage(std::string messageStr,
            LoggingTypes::LoggingClientType type, int id);

    private:
        Vout();
        ~Vout();

        /** Static instance for automagically starting and cleaning up. */
        static Vout staticInstance;

        /** Worker thread. */
        std::thread loggingThread;
        /** Thread run flag used to stop the thread. */
        volatile bool threadRunning;

        /** Mutex for thread-safe access to message queue. */
        std::mutex lMutex;
        /** Condition variable for waiting idle worker thread. */
        std::condition_variable condVariable;
        /** Queue of logging messages. */
        std::queue<LoggingMessage*> messages;

        /** Worker thread function. */
        void threadFunction();

}; /* class Vout */

}; /* namespace Vesper */


#endif /* VOUT_HPP_INCLUDED */
