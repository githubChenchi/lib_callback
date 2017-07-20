#include <stdio.h>
#include "callback.h"

int callback_event1_1( void * arg)
{
	printf("callback_event1_1 \r\n");
}

int callback_event1_2( void * arg)
{
	printf("callback_event1_2 \r\n");
}

int callback_event1_3( void * arg)
{
	printf("callback_event1_3 \r\n");
}

int callback_event1_4( void * arg)
{
	printf("callback_event1_4 \r\n");
}

int callback_event1_5( void * arg)
{
	printf("callback_event1_5 \r\n");
}

int callback_event1_6( void * arg)
{
	printf("callback_event1_6 \r\n");
}

int callback_event1_7( void * arg)
{
	printf("callback_event1_7 \r\n");
}

int callback_event1_8( void * arg)
{
	printf("callback_event1_8 \r\n");
}

int callback_event1_9( void * arg)
{
	printf("callback_event1_9 \r\n");
}

int callback_event1_10( void * arg)
{
	printf("callback_event1_10 \r\n");
}

int callback_event1_11( void * arg)
{
	printf("callback_event1_11 \r\n");
}

int callback_event1_12( void * arg)
{
	printf("callback_event1_12 \r\n");
}

int callback_event2_1( void * arg)
{
	printf("callback_event2_1 \r\n");
}

int callback_event2_2( void * arg)
{
	printf("callback_event2_2 \r\n");
}

int callback_event3_1( void * arg)
{
	printf("callback_event3_1 \r\n");
}

int callback_event10_1( void * arg)
{
	printf("callback_event10_1 \r\n");
}

int callback_event10_2( void * arg)
{
	printf("callback_event10_2 \r\n");
}

int main(void)
{
	callback_register(EVENT_1, callback_event1_1);
	callback_register(EVENT_1, callback_event1_2);
	callback_register(EVENT_1, callback_event1_3);
	callback_register(EVENT_1, callback_event1_4);
	callback_register(EVENT_1, callback_event1_5);
	callback_register(EVENT_1, callback_event1_6);
	callback_register(EVENT_1, callback_event1_7);
	callback_register(EVENT_1, callback_event1_8);
	callback_register(EVENT_1, callback_event1_9);
	callback_register(EVENT_1, callback_event1_10);
	callback_register(EVENT_1, callback_event1_11);
	callback_register(EVENT_1, callback_event1_12);

	callback_register(EVENT_2, callback_event2_1);
	callback_register(EVENT_2, callback_event2_2);

	callback_register(EVENT_3, callback_event3_1);
	callback_register(EVENT_3, NULL);

	callback_register(10, callback_event10_1);
	callback_register(10, callback_event10_2);

	for(event_t event = EVENT_0; event < EVENT_MAX; event++)
	{
		callback_execute(event);
	}

	printf("\r\n ######## unregister ! \r\n");

	callback_unregister(EVENT_2, callback_event2_1);
	printf("callback_event2_1 unregister \r\n");

	callback_unregister(EVENT_2, callback_event2_2);
	printf("callback_event2_2 unregister \r\n");

	for(event_t event = EVENT_0; event < EVENT_MAX; event++)
	{
		callback_execute(event);
	}

	printf("\r\n ######## Done! \r\n");
	
	return 0;
}
