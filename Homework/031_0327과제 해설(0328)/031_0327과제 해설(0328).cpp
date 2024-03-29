﻿// 034_0327과제 해설.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 포인트: 

// a클래스가 b클래스를 참고해서 코드를 사용하도록 할 것 
// void input(콘솔게임스크린 _콘솔) <= 이대로 넘기면 200바이트가 넘어가지만
// 참조로 넘기면 8바이트가 넘어가기 대문에 이쪽이 훨씬 경제적임 
// 콘솔게임 스크린이 없을 가능성이 있다면* , 없다면 &

// switch문 안에서 변수 선언하는 법 

// const 를 적절한 위치에 넣어줘야하는 것 ,판단근거는 함수 내부에서 자신의 내용이 바뀌나, 안 바뀌나가 근거. 
                // 클래스 만들떄 그래서 무조건 const를 넣어야 할것. 
                // const의 유무로 함수를 짠 개발자의 의도를 알수 있음. 

// 레퍼런스 사용시 > player 안에 반드시 콘솔게임스크린이 넣어진 상태여야 함

// >> 포인터의 경우: 원할 때 콘솔게임스크린을 넣어줄 수 있음. >> 레퍼런스: 콘솔게임스크린을 강제할 수 있음. 

// 0328 강의 풀이 꼭 보기.

        // 밀린 숙제: 0317(함수짜보기), 0323(게임 만들기), 0327(23일걸 class로 변경해보기) 3개 



// 메인콘솔스크린 안에 모든걸 집어넣고 구현하는 방식 선호.
// >> 단, 이때 메인콘솔스크린은 private로 선언되어야 함. (그래야 1개만 생김) 


// 메인콘솔스크린(클래스)와 int를 동일하게 생각하라는 건, int도 누군가가 정의해준 클래스라는걸 이해하라는 뜻.
// 이때 메인콘솔스크린은 모든 클래스에서 참조해서 사용해야하기때문에 public을 생성자로 두어서 만든거임.
// 그걸 하라는 의미. 

// 다양한 방법이 있음을 이해할것. 



#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}


