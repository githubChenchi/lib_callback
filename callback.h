#ifndef _CALLBACK_H
#define _CALLBACK_H

typedef enum {
	EVENT_0,
	EVENT_1,
	EVENT_2,
	EVENT_3,
	EVENT_4,
	EVENT_5,
	EVENT_6,
	EVENT_7,
	EVENT_8,
	EVENT_9,
	EVENT_MAX	/* the max number of the event to be registered */
} event_t;

#define REGISTER_NUM_MAX	10	/* the max number that is allowed to be registered of every single event */

typedef int (* callback_t)(void * arg);

typedef struct {
	callback_t cb[REGISTER_NUM_MAX];	/* save the callback functions that have been registered */
	unsigned int count;					/* save the number of the callback functions that have been registered */
} callback_s;

extern callback_s callback[EVENT_MAX];	/* save the register info of every single callback function */
extern void callback_register( event_t event, callback_t cb_fn );	/* callback register API */
extern void callback_execute( event_t event );						/* callback execute for every single event */

#endif
