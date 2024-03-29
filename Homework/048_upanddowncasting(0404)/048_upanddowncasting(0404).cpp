﻿// 048. 업다운캐스팅 cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 암시적 형변환에 대해서 꼭 익히고 들어가기. 
// 업캐스팅, 다운캐스팅 

#include <iostream>

class FightUnit
{
public:
    void damage(int _damage)
    {
        Hp -= _damage;
    }

    virtual int GetAtt()// 이게 플레이어일때, 몬스터일때 다르게 동작하게 구현해야 함
				// 플레이어의 공격력은 자신의 레벨에 영향을 받아야하는데, 몬스터일때는 그게 없기 때문
				// -> 이것을 해결하기 위함이 "다형성" (겉보기엔 플레이어 유닛이지만, 그속내는 플레이어-몬스터-그 외 여러기능을 수행함) 
		// ㄴ 따라서 geatt가 각자 자식형(플레/몬스터)일때 각 방식으로 동작하게 돕는 문법이 있어야 한다. 
		// 그걸 하는것이 버추얼!! 

		// 가상함수의 매커니즘: 자식이 getatt를 새롭게 정의하지 않으면 부모형으로 동작하고. 
		// 자식이 getatt를 새롭게 정의하면 자식의 형으로 동작한다. 단, 선언 방식은 부모와 동일해야한다. 
		// 사용법: 자식형에 이렇게 여러가지로 동작했으면 하는 함수를 복붙한다. (예시 겟 어택)하단으로 내려가셈
    {
        // return FightUnit::Getatt() + lv; 
        return Att;
    }

private:
    int Hp = 100;
    int Att = 10;
};

class Player : public FightUnit
{
public: // 가상함수 사용법 이어서 <오버라이드> // 가상함수 오버라이드 다시 공부해보기 
    // 오버라이드 문법이라고 합니다.
    // 명시적으로 override했다는 것을 표현해주는것이 좋은데
    // 내용은 함수 뒤에 
    // 붙이지 않아도 오버라이드는 되지만 명시적이 아닌것을 
    // 선생님은 굉장히 싫어하기 때문에 붙여줄 것이다.
    int GetAtt() override
    {
        return FightUnit::GetAtt() + Lv; // 이 형식대로 써줘야 가상함수를 쓸 수 있음. 
    }

    //void Test() override
    //{
    //}

private:
    // 공격력이 레벨에 영향을 받게 
    int Lv = 1;
};

class Monster // : public FightUnit
{

}; // 이거 그냥 만들어둔 몬스터 클래스인듯. 주석을 :public 앞에 걸면 상속이 끊김. 

// < 업캐스팅을 이용한 함수의 예시 > 
// 2. 파이트유닛:"싸움" 자체를 구현한 함수 (대상은 상관없게) 
// ㄴ 이제 파이트 유닛의 "대상" 을 구현한게 Fight 
// ㄴ 정확히는 왼쪽이 때리고 오른쪽이 대미지 받음 & 오른쪽이 떄리고 왼쪽이 대미지를 받음을 구현. 
// : 플레이어에 포인트를 걸어서 파이트 유닛을 사용할 수 있게 구현함. 

// 업캐스팅을 이용한 함수를 만들게 됩니다.
void Fight(FightUnit* _Left, FightUnit* _Right)
{

    // 디버깅 : 이게 내가 원하는대로 돌아가는지 확인하기.
     // 레프트att에는 몬스터att, 라이트att에는 플레이어att가 들어갈 수 있게. (단, 플레이어는 레벨을 반영한 공격력) 

    int Leftatt = _Left->GetAtt();
    int Rightatt = _Right->GetAtt(); // 디버깅하기 위해서 아래 두줄보다 위 두줄처럼 치는게 좋음. 

    // 익숙해지면 아래처럼 치면 됨 //  

    _Right->damage(_Left->GetAtt());
    _Left->damage(_Right->GetAtt()); 

    // 즉, 부모클래스는 파이트유닛은 자식(플레이어/몬스터)를 알고 있으면 안된다. 
    // 반드시 문제가 생기기 때문임. 

    // 다운 캐스팅을 사용하는 건 안 좋은 방법. >> 무슨 일이 일어날 수 없음. 
    // Player* PlayerPtr = (Player*)_Left;
    // _Right->damage(PlayerPtr->GetPlayerAtt()); // 이럴땐 좌, 우 를 확실하게 알려줄 수 있는걸 말해줘야함. 


    // 다운캐스팅: 부모형을 자식형으로 바꾼다. 부모를 여러개의 자식형 중 하나로 바꾸는 것. (이걸 안전하게 하는것이 안됨) 
    // 이건 강제 캐스팅이고 직접 구현해줘야함. 
    // 진짜 쓰고 싶으면 안전하게 쓰는 방법(아직 안배움)을 사용해서 해야 함. 

        //FightUnit* Ptr; 
        //Player*PlayerPtr =(Player*)Ptr; <- Player와 Monster의 자식형 중 강제로 내가 고정해준거임. 

    // 업캐스팅: 자식형을 부모형으로 바꾼다 (무조건 됨) 
    // 자식형은 이미 부모형을 다 들고 있기 때문. 반대는 아니므로. 
}

int main()
{
    {
        // 부모형을 자식형으로 바꾼다. => 위험성이 있다.
        // 강제 캐스팅이고 내가 쳐줘야 한다.
        FightUnit* Ptr;

        // 다운캐스팅을 꼭 해야하는 경우를 본적이 없습니다.
        // 그래서 위험하다는 겁니다.
        Player* PlayerPtr = (Player*)Ptr;

        // 업캐스팅 => 자식형을 부모형으로 만드는건데 그냥 무조건 됩니다.
        // 다운캐스팅 => 부모형을 여러개의 자식들중 하나로 선택하는것.
        // 안전하게 다운캐스팅을 하는 방법이 존재하고 그 이외의 방식으로 
        // 그냥 하면 절대로 안됩니다.
    }

    {
        Player NewPlayer;
        Monster NewMonster;

        Player* PlayerPtr = &NewPlayer;

        // 업캐스팅이라고 합니다.
        FightUnit* Ptr = PlayerPtr;
        Ptr = &NewMonster;

        Fight(&NewMonster, &NewPlayer);

        // 1. 
    // 왜 플레이어는 파이트 유닛의 포인터가 될 수 있을까?
    // ㄴ 플레이어가 파이트 유닛을 상속받았고, 플레이어의 에모리에 파이트 유닛의 모든 내용이 들어있기 때문.
    // 플레이어의 메모리 [상속:파이트유닛][플레이어의 내용]
    // 이 현상을 업 캐스팅이라고 함. 

    }
}
