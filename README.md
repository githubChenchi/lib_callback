# API说明手册

---

## 1. 概述  

&emsp;&emsp;实现了同一事件的发生支持多次回调函数的注册，这样可以在不同的程序文件中，对同一事件的发生进行不同的处理，以满足应用的需求。  

&emsp;&emsp;该库使用GCC编译，亲测OK。test文件夹内附有测试例程，如果在其它编译器下，编译出现问题，或不能正常运行，请根据所使用的编译器，优化代码。  

&emsp;&emsp;如果有需要优化的地方，或因为需要支持其它编译器而改变了代码，请新建分支，并提pull request，一起为开源做出贡献，谢谢！  

## 2. 事件枚举、函数型指针、回调注册控制块结构 及 常量  

### 2.1 事件枚举  

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

&emsp;&emsp;根据不同的应用自行定义。  

### 2.2 函数型指针  

	typedef int (* callback_t)(void * arg);

&emsp;&emsp;定义`callback_t`函数指针数据类型，指向（输入参数为`void * arg`，返回值为`int`类型）的函数。  

### 2.3 回调注册控制块结构

	typedef struct {
		callback_t cb[REGISTER_NUM_MAX];	/* save the callback functions that have been registered */
		unsigned int count;					/* save the number of the callback functions that have been registered */
	} callback_s;  

&emsp;&emsp;成员`cb`保存同一事件每一个被注册的回调函数的入口地址。  
&emsp;&emsp;成员`count`保存同一事件被注册的回调函数的数目。  

### 2.4 常量

	#define REGISTER_NUM_MAX	10	/* the max number that is allowed to be registered of every single event */  

&emsp;&emsp;指明每个事件最多被允许注册的回调函数的最大的数目。  

## 3. API  

### &emsp;&emsp;3.1 `extern void callback_register( event_t event, callback_t cb_fn )`  

#### &emsp;&emsp;参数  

		event : 事件  
		cb_fn : 传递回调函数入口  

#### &emsp;&emsp;返回值  

		无  

### &emsp;&emsp;3.2 `extern void callback_execute( event_t event )`  

#### &emsp;&emsp;参数  
	
		event : 事件  

#### &emsp;&emsp;返回值  

		无  
