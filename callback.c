#include <stdio.h>
#include "callback.h"

callback_s callback[EVENT_MAX] = { { { NULL }, 0 } };

void callback_register( event_t event, callback_t cb_fn )
{
	if(event >= EVENT_0 && event < EVENT_MAX)
	{
		if(callback[event].count < REGISTER_NUM_MAX)
		{
			callback[event].cb[callback[event].count++] = cb_fn;
			printf("[SUCCESS] event [%d] has been registered [%d] times \r\n", event, callback[event].count);
		}
		else
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
	for(int count = 0; count < callback[event].count; count++)
	{
		callback[event].cb[count](NULL);
	}	
}
