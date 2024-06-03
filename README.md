# G4decay_spectrum
Isotopes decay simulation using Geant4  
![Cow2](https://github.com/lcyf9102s/G4decay_spectrum/raw/main/images/vis.png "Cow1")  
通过改变质子数和原子量来改变核素种类，construction.cc中可以直接改探测器种类（NaI闪烁体、高纯锗、pips）  
输出使用ROOT将dat数据绘制成多道分析器能谱图，道数和能量范围可以根据需要设置。  
P.s. 使用pips探测器模拟α粒子测量时要设置真空材料，否则输出能谱峰漂移会比较严重。  

## Examples
1. Co-60, 0~3 MeV, 1024 Channels.  
![Cow2](https://github.com/lcyf9102s/G4decay_spectrum/raw/main/images/Co60_0_3_1024.png "Cow1")  

2. Cs-137, 0~1 MeV, 1024 Channels.
![Cow2](https://github.com/lcyf9102s/G4decay_spectrum/raw/main/images/Cs137_0_1_1024.png "Cow1")  
