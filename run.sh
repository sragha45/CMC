#python host_discover.py
g++ requestSender.cpp VcInterface.cpp  Consumer.cpp Provider.cpp CmcClusterMo.cpp cmcRequestListener.cpp test2.cpp -pthread -o cmc -lpython2.7 -lboost_python

#g++ -I. test2.cpp -pthread -o cmc
#g++ -c -fPIC boosts.cpp
#g++ -c -fPIC test2.cpp
#g++ -c -fPIC requestSender.cpp
#g++ -c -fPIC VcInterface.cpp
#g++ -c -fPIC Consumer.cpp
#g++ -c -fPIC Provider.cpp
#g++ -c -fPIC CmcClusterMo.cpp
#g++ -c -fPIC cmcRequestListener.cpp
#g++ -shared -Wl,-soname,boosts.so -o boosts.so boosts.o test2.o requestSender.o VcInterface.o Consumer.o Provider.o CmcClusterMo.o cmcRequestListener.o -lpython2.7 -lboost_python
./cmc

