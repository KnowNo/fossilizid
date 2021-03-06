/*
 * service.h
 *
 *  Created on: 2015-1-11
 *      Author: qianqians
 */
#ifndef _service_base_h
#define _service_base_h

#include <set>

#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

#include "../../uuid/uuid.h"
#include "../../context/context.h"

#include "../interface/service.h"
#include "../interface/channel.h"
#include "../interface/semaphore.h"

#include "module.h"

namespace Fossilizid{
namespace juggle{

class juggleservice : public service{
public:
	juggleservice();
	~juggleservice();

public:
	/*
	 * initialise service
	 */
	virtual void init();

	/*
	 * drive service work
	 */
	virtual void poll();

	/*
	 * add rpcsession
	 */
	virtual void add_rpcsession(channel * ch);

	/*
	 * remove rpcsession
	 */
	virtual void remove_rpcsession(channel * ch);
	
	/*
	 * unixtime
	 */
	virtual uint64_t unixtime();

public:
	/*
	 * register semaphore
	 */
	void register_semaphore(semaphore * _semaphore);

	/*
 	 * register module method
	 */
	void register_module_method(std::string methodname, boost::function<void(channel *, boost::shared_ptr<object>)> modulemethod);

	/*
	 * register rpc callback
	 */
	void register_rpc_callback(uuid::uuid, boost::function<void(boost::shared_ptr<object>)> callback);
	
	/*
	 * get current context
	 */
	context::context get_current_context();

	/*
 	 * wake up context
	 */
	void wake_up_context(context::context ct);

	/*
 	 * scheduler
	 */
	void scheduler();

private:
	/*
	 * set current context
	 */
	void set_current_context(context::context _context);

	/*
	 * loop main
	 */
	void loop_main();

private:
	boost::thread_specific_ptr<context::context> tss_current_context;

private:
	boost::mutex mu_method_map;
	boost::unordered_map<std::string, boost::function<void(channel *, boost::shared_ptr<object>)> > method_map;
	
	boost::mutex mu_method_callback_map;
	boost::unordered_map<uuid::uuid, boost::function<void(boost::shared_ptr<object>)> > method_callback_map;

private:
	boost::mutex mu_wake_up_vector;
	std::vector<context::context> wait_weak_up_context;

	boost::mutex mu_vsemaphore;
	std::map<time_t, context::context> vsemaphore;

private:
	boost::mutex mu_channel;
	std::set<channel * > set_channel;

	boost::mutex mu_new_channel;
	std::vector<channel * > array_new_channel;

private:
	time_t clockstamp;
	time_t timestamp;

};

void create_module();

} /* namespace juggle */
} /* namespace Fossilizid */

#endif //_service_base_h