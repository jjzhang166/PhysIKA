#ifndef FRAMEWORK_ACTION_H
#define FRAMEWORK_ACTION_H

#include "Physika_Framework/Framework/Node.h"

namespace Physika
{
	class Action
	{
	public:
		Action();
		virtual ~Action();

		virtual void Process(Node* node);
	private:

	};
}

#endif
