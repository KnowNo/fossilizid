PROJECT(test)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 

ADD_SUBDIRECTORY(test_container)
ADD_SUBDIRECTORY(test_pool)
ADD_SUBDIRECTORY(test_context)
ADD_SUBDIRECTORY(test_remote_queue\\client)
ADD_SUBDIRECTORY(test_remote_queue\\server)
ADD_SUBDIRECTORY(test_udp\\client)
ADD_SUBDIRECTORY(test_udp\\server)
ADD_SUBDIRECTORY(test_service\\client)
ADD_SUBDIRECTORY(test_service\\server)