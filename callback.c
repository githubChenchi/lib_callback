#include <stdio.h>
#include "callback.h"

callback_s callback[EVENT_MAX] = { { { NULL }, 0 } };

void callback_register( event_t event, callback_t cb_fn )
{
	int count = 0;
	
	if(event >= EVENT_0 && event < EVENT_MAX)
	{
		for(count=0; count<REGISTER_NUM_MAX; count++)
		{
			if(callback[event].cb[count] == NULL)
			{
				if(cb_fn)
				{
					callback[event].cb[callback[event].count++] = cb_fn;
					printf("[SUCCESS] event [%d] has been registered [%d] times \r\n", event, callback[event].count);
				}
				else
				{
					printf("[WARNING] event [%d] callback function can not be NULL \r\n", event);
				}
				break;
			}
		}
		if(count == REGISTER_NUM_MAX)
		{
			printf("[FORBIDDEN] the callback functions register count of this event [%d] has been up to max \r\n", event);
		}
	}
	else
	{
		printf("[ERROR] illegal event [%d] \r\n", event);
	}
}

void callback_execute( event_t event )
{
	int count = 0;

	for(count=0; count<REGISTER_NUM_MAX; count++)
	{
		if(callback[event].cb[count])
		{
			callback[event].cb[count](NULL);
		}	
	}
}

void callback_unregister( event_t event, callback_t cb_fn )
{
	int count = 0;
	for(count=0; count<REGISTER_NUM_MAX; count++)
	{
		if(callback[event].cb[count] == cb_fn)
		{
			callback[event].cb[count] = NULL;
			callback[event].count--;
			printf("[SUCCESS] event [%d] has been registered [%d] times \r\n", event, callback[event].count);
			break;
		}
	}
}
