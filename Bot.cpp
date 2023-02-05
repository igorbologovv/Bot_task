#include <iostream>
#include <random>
struct state{
     int flag;
     int one=1;
};

class BOT{
public:
     int pos = 0;
     int par_pos = 0;
     struct state S{};

    BOT(int pos)
     {
       this->pos = pos;
       this->par_pos = pos;
     }
};

int action(bool on_para,  struct state& S)
{
     if(S.one != -1){
              S.one -=1;
     }
     if(on_para == true ){
     S.flag = 1;
     S.one = 1;
     }
     if(S.flag == 1 && S.one == 1 ){
          S.one = 2;
          return 1;
     }
   //=================================
     if(S.one == 0 && S.flag == 0){
          return S.one;
     }
     else if (S.one == -1 and S.flag == 0){
          S.one = 1;
          return S.one;
     }
     return 0;
}


int main(){
    std::random_device generator;

     std::uniform_int_distribution<int> distribution(-100,100);

    BOT bot_1(distribution(generator));
    BOT bot_2(distribution(generator));
    auto d = abs(bot_1.pos - bot_2.pos);

     for (int i = 0; ;i++){

            bool bot1_on_para = (bot_1.pos == bot_2.par_pos);
            bool bot2_on_para = (bot_2.pos == bot_1.par_pos);
          // std::cout<<bot_1.pos <<"    "<<bot_2.pos<<std::endl;
          if(bot_1.pos == bot_2.pos)
          {
              std::cout<<"Found in "<< i << " steps of " << d <<std::endl;
               return 0;
          }

          bot_1.pos += action(bot1_on_para, bot_1.S);
          bot_2.pos += action(bot2_on_para, bot_2.S);

     }
return 0;
}




