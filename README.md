# UE4_LearnBlueprint
### 学习资料
[深入Unreal蓝图开发：将异步操作封装为蓝图节点
](https://neil3d.gitee.io/unreal/bp-async.html)

[自定义高级蓝图节点(上)](https://neil3d.github.io/unreal/custom_bp_node.html)  
[自定义高级蓝图节点(中)](https://neil3d.github.io/unreal/bp_dynamic_pin.html)  
[自定义高级蓝图节点(下)](https://neil3d.github.io/unreal/bp_node_handler.html)

[Latent Action创建案例（英文原版）](https://programmersought.com/article/95054347848/)

[Latent Action创建案例（中文机翻版）](https://blog.csdn.net/flowersplug/article/details/80408493)  

### 知识点记录
- 宏和函数
    - 宏可以用任意个或者没有输入和输出执行引线。函数只有一个
    - 函数可以override，宏不行
    - 宏里可以用delay之类的LatentAction，函数不行

- 异步节点和LatentFunction
	- LatentFunction本质上还是逐帧调用，然后判断条件
	- 异步节点是真正的异步，同时它还有同步执行的输出引脚
	- 在函数内虽然可以使用异步节点但是功能会受限，只能使用它的同步输出引脚，异步功能不能用。而LantentFunction在函数里面完全不能使用。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210704200420269.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)
