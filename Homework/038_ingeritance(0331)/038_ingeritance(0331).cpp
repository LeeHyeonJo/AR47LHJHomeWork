﻿// 038_inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 0331 : 클래스의 상속 -> 접근제한지정자에 따른 상속 여부 잘 복습해두기 (그냥 상속, 상속의 상속도 해보며 생각해보기) 

#include <iostream>

// 1. 캡슐화: 클래스가 특정 기능들을 내부에 품고잇는 특성 그 자체를 말함
// 캡슐화를 지원하는 문법: 접근제한 지정자, 클래스 그 자체 


// 2. 상속: 특정 개념의 특성들을 하위 개념들이 물려 받는 것.
    // Is a 관계라고 표현함: 이거 뭔지 다시 찾아보셈 
    // Has a 관계: 플레이어(클래스)가 내부에 멤버변수로 아이템을 가지고 있는 경우. 
        //ex) 아이템 클래스 ) 포션, 무기 ==> 포션,무기는 아이템이다 = 헤즈 어 관계 . 


// 상속을 의미하는 문법

//1. 기본 클래스를 만든다. -> 상위클래스에 그 기능이 가져야 할 모든 속성을 넣어준다. 
class item
{
public:
    int gold = 10;
    void buy() {
    }
};

// : public item 상속을 의미하는 문법 -> 상속관계가 된다 
// 아래처럼 선언하면 됨. 
class weapon : public item
{
    //public:
    //    int gold = 10;
    //    void buy() {
    //    } <- 상속이란건 이렇게 엄마클래스의 내부내용을 복붙. 
        // !! 이때, 생성자끼리 범위가 충돌할땐 좁은쪽을 따라감 
        // !! 즉, private는 상속되지 않는다고 이해해도 됨. 
        // 복붙해서 생성자를 비교하고 좁은쪽을 남긴다 (끈데 private는 자식에게 공개되지 않으므로 소용x)

public:
    int gold = 5;

};




int main()
{
    weapon nweapon; // 새로운 무기 만듬
    nweapon.gold // 상속을 받았으므로 ogold를 사용할 수 잇음. 
};
