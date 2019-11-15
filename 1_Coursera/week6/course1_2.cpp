/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-13 19:43:23
 */
#include <iostream>
using namespace std;
//多态
class CCreature{
    protected:
        int m_nLifeValue, m_nPower;
    public:
        virtual void Attack(CCreature *pCreature){}
        virtual void Hurted(int nPower){}
        virtual void FightBack(CCreature *pCreature){}
};

class CDragon: public CCreature{
    public:
        virtual void Attack(CCreature *pCreature);
        virtual void Hurted(int nPower);
        virtual void FightBack(CCreature *pCreature);
};
void CDragon::Attack(CCreature *p){
    p->Hurted(m_nPower);
    p->FightBack(this);
}
void CDragon::Hurted(int nPower){
    m_nLifeValue -= nPower;
}
void CDragon::FightBack(CCreature *p){
    p->Hurted(m_nPower/2);
}