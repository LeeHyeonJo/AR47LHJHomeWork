﻿// 016_class3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 플레이어를 만들고, 클래스를 선언하는걸 다시 보자. 
// 여기 이어서 쭉 함. 

#include <iostream>

class Player //1. 플레이어를 만들어준다
{
public:
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int speed = 3;
    // 2. 플레이어를 이루는 요소(멤버 변수)들을 넣어준다. 
    // 이 멤버변수는 바로 초기화도 가능하다. 

        // 클래스 문법에서는 속성이나 행동을, 내가 외부에 공개할지 안 할지를 결정할 수 있다. 
        // 외부란? 클래스의 스코프 를 제외한 모든 영역. 따라서 메인은 외부가 됨. 
        //  <접근제한 지정자>       내부코드          자식코드                외부
        // 1. public:                공개                공개                 공개
        /*      int Att = 10;
                int Def = 2;
          2. protected:              공개                공개                 비공개
                int Hp = 100;
          3. private:                공개                비공개                 비공개
                int speed = 3;*/
                // 접근제한 지정자는: 만들어진 위치부터 아래까지 새로운 접근제한 지정자가 나오는 구간까지 적용됨. 
};      // 디폴트 접근제한 지정자는 private!! 


class monster //2. 몬스터 
{
private:
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int speed = 3;

// 클래스 내부 

public:
    int gethp()
    {
        return Hp;
    }

    int sethp(int Hp1)
    {
        // 몬스터 클래스 내에서 일부러 함수 만들어서 선언하는 이유
        // 이 경우 hp를 수정할 수 있는 통로를 하나로만 만들기 위해서. 
        // 외부 참조 불가능하네 프라이베잇 걸고, public 으로는 이 클래스 내에서만 풀어두고 연산할 것
        // 모든 코드의 기본임 걍 public 걸어두고 빼와쓰는 방식은 매우 위험함. 항상 함수로 선언하는 걸 기본으로 생각할 것. 
        // ++ 포폴할때 선생님은 public 코드 종종 쓸 수도 있음 .. 그러니 이 부분은 내가 수정해야 함. 
        Hp = Hp1;

        if (0 == Hp1)
        {
            int a = 0; 
        }

    }


};      



//0322 여기서 더 진도나감 

int main() // 여기 잘 작성했는지 확인하기. 

{
    // Player nPlayer; // 3.뉴 플레이어를 하나 만든 후, 클래스에 정의한 걸 가져옴. 

    // nPlayer. // .을 찍어서 클래스 내부의 멤버변수에 접근할 수 있음// - 이거 잘 들어간거 다시 확인해보기. 

    //여기는 외부임. 



    // 여기에 몬스터함수 들어가더라 필기 보고 확인 
    Player nPlayer = Player();


    // 지정자를 사용하는 이유가 이 객체지향 함수를 지키기 위해서 (난잡하게 빼와쓰는거 안됨) 





    // 접근제한 지정자: public으로 사용하는 것 - 보통 행동을 퍼블릭으로 만듦. 
    // nPlayer.att
    
    // 객체의 사용범.  누르고 플레이어 내부에 있는 것을 꺼내서 사용한다 (ex. nplayer.att 이렇게) 


}


