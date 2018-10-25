#include "Factory.h"

int PlayerFactory::_lazy = 0;
PlayerFactory::Workers* PlayerFactory::staff;


PlayerFactory::Workers* PlayerFactory::Staff() {
         if (_lazy == 0) {
                  staff = new Workers;
                  _lazy = 1;
         }
         return staff;
}

Player* PlayerFactory::Produce(Key k) {
         Workers::iterator it = Staff()->find(k);
         if (it != Staff()->end()) {
                  return it->second->Produce();
         } else {
                  return NULL;
         }
}

void PlayerFactory::Register(Key k, Worker* GPP) {
         Staff()->insert(Pair(k,GPP));
}
