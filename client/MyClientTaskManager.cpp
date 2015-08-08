/*************************************************************************
    > File Name: MyClientTaskManager.cpp
    > Author: huangyun
    > Mail: 895175589@qq.com 
    > Created Time: Sun 09 Aug 2015 01:01:25 AM
 ************************************************************************/

#include "MyClientTaskManager.h"

namespace MyNameSpace
{
	void MyClientTaskManager::addTask(MySockClientTask *task)
	{
		MyScopeLock lock(mLock);
		mTasks[task->getId()] = task;
	}
	
	void MyClientTaskManager::removeTask(MySockClientTask *task)
	{
		MyScopeLock lock(mLock);
		mTasks.erase(task->getId());
	}

	bool MyClientTaskManager::doProcessMsg()
	{
		MyScopeLock lock(mLock);
		for (Container_IT it = mTasks.begin(); it != mTasks.end(); ++it)
		{
			it->second->processMsg();
		}
	}
}
