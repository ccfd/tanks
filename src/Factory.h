#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include <string>
#include <map>

class Player;

class GenericPlayerProducer {
public:
        virtual Player* Produce()=0;
};

template <class P>
class PlayerProducer : public GenericPlayerProducer {
public:
        virtual Player* Produce() { return new P; }
};

class PlayerFactory {
public:
        typedef std::string Key;
        typedef GenericPlayerProducer Worker;
private:
        typedef std::map < Key, Worker* > Workers;
        typedef std::pair< Key, Worker* > Pair;
        static int _lazy;
        static Workers* staff;
        static Workers* Staff();
public:
        static Player* Produce(Key k);
        static void Register(Key k, Worker* GPP);
};

template <class P> class RegisterPlayer {
public:
        RegisterPlayer(PlayerFactory::Key k) {
                PlayerFactory::Register(k, new PlayerProducer<P>);
        }
};

#endif // FACTORY_H