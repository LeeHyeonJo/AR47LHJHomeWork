﻿// 022_member.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 변수나 클래스만 말하면 못알아들을 수 있음. 따라서 코드 독해를 잘 해야해. 

#include <iostream>

// <영역> 에 대한 설명
// 어느 영역에도 속하지 않는 곳을 전역이라고 한다. 



// 전역 안에 선언된 함수를 전역함수라고 한다. 
// 메인과 테스트가 여기서 전역함수임 

// 전역 변수: 전역에 선언된 변수를 칭함. 
int globalvalue = 10;

void test()
{

}


// 다음 설명
// 멤버 공간: 사용자 정의 자료형(클래스) 내부의 공간을 의미함. 
class player
{
private: // 디폴트가 프라이베이트지만, 명시적으로 선언하는 걸 추천
    void damage(int _att) // 이건 멤버 함수
    {
                // 여긴 그냥 지역~
        int a = 0 // 이건 다시 지역변수인거에 주의 !!!!! 
    }


    int hp; // 따라서 얘는 "멤버 변수"  라고 부름 (지역변수가 아님에 주의) 

};

int main()
{
    // 정리! 

    // C++에서 영역에 대한 구분: 1, 전역 2, 지역 3 멤버 4 이름있는 namespace

    // 이름있는 namespace에 대해선 이 다음에 설명. 

    std::cout << "Hello World!\n";
}

