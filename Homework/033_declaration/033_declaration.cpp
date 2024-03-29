﻿// 036_declaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 문법, 함수의 선언부과 구현부를 분리해야하는 이유. 
// 선언만으로도 충분히 돌아가는 이유: *
// 내용: 함수의 오버로드 / 클래스의 오버로드 
// 포인트: 6),7),8) // 클래스 선언과 구현의 구분

// 따라서 전방선언만 잘 쓰면, 클래스구현순서를 신경쓰지 않아도 괜찮음.(그 내부에서 내용만 구현하지 않으면) 

#include <iostream>

// 함수란?" 선언과 함수체를 같이 놓은 문법
// >> 함수 선언만 따로 놓는 경우가 잇음 (void function();  이런거 ) 
// >> 이걸 왜 하는가? : 닭과 달걀인 관계의 함수를 짜야할 때, 함수는 위에서부터 구현되잖아.
// 그런데 아직 구현도 안된 함수를 넣어달라는 코드를 짜야하는 상황에서 - 
// 일단 상단에 있다고 "선언" 먼저 한 수 갖다쓰는거임. "구현"은 나중에. 
                // 일반적으로 선언은 항상 위에 올려둠(존재만 인식) 

 //* 선언만으도 돌아가는 이유: main의 입장에선 선언에서 쓰인 "리턴" 값이 중요함 (int - 4바이트, n바이트..이게 중요한거임) 
// main 입장에선 내부 함수 안 중요함. 리턴 값을 알아야 그에 해당하는 메모리를 할당할 수 있기 때문. 

void function() // 함수의 선언

{

} // 이것이 함수체 


// 왜? 의 예시: 0은 2를 호출하고, 1은 0을 호출하고, 2는 0을 호출하는 경우를 가정. 
void function0()
{
    function2();
}

void function1()
{
    function2();
}

void function0();
{
    function1();
}

// >> 이렇게 닭이 먼저냐, 달걀이 먼저냐 하는 상황이 생길수있음. 
// 이걸 해결하기 위해서 "함수 선언부"와 "구현부"를 분리함. 

// 1. 선언부의 분리. 
// 구현부가 어딘가에 "있을거라고" 믿고 일단 머리만 부른거임. 
void function0();
void function1();
void function2();

// 같은 이름으로 n개 선언해도 컴파일러가 알아서 1개로 인식함 선언이기 때문!!! 

// 3. 그러나 클래스는 다르다!! 
// 문법상 선언과 구현이 내부에서 섞여있을수도,아닐수도있음.
// 1)클래스 자체는 동일한 이름으로 선언할 수 없다.

class player
{


public:
    //5) static 함수의 경우, 멤버함수와 동일한 규칙을 적용한다. (전역에서 구현 불가능하다는 뜻) 
    static void globalfunction()
    {


    }

private:
    //6) static 멤버 변수의 경우, const가 붙으면 구현체를 따로 둘 수가 없다. (선언과 분리 불가능) 
    // 상수로 취급되어 코드 영역에 가버리기 때문.  = 리터럴 초기화가 가능 (선언동시초기화)
    static const int gvalue0 = 0; // 의미: gvalue가 싹 다 0으로 바뀜(상수로) , 앞으로 보이는 gbalue는 전부 0으로 바꾼다. 

    //7) static 멤버 변수의 경우, const가 안 붙으면 데이터 영역으로 위치하게 된다. 
    // 선언으로만 취급되며, 초기화가 가능하다. = 리터럴 초기화가 불가능 
    // player에 속한 static 전역변수인 g벨류가 잇을거야......라는 설계도!!!!!!!!!! 
    // static const int gvalue = 0; // 이런게 안됨 

    static const int gvalue1; // 이렇게 해야 함. 

    // 에러: 외부기호~~ = 실체가 없다. 구현하지 않았다는 의미다. 

public:
    // 2)그러나 클래스 "내부"의 함수는 별개로 선언만 할 수 있음!!! 
    player();

    //4) 일반적인 멤버변수는 선언인 동시에 구현임. (실체를 둘 필요가 없음) 
    int a;

    // 3) 멤버함수의 fullname은 
    // 클래스명::함수 명임을 잊지 말것
    // 하단처럼. 
public:

    void damage() // =  player::damage()
    {


    };

};

// 8)실체가 이거임
// 이렇게 지벨류가 먼지 선언해줘야함. 
int player::gvalue = 0;

int main()
{
    std::cout << "Hello World!\n";
}

// 2. 구현부는 대체로 메인 아래에 둠. 
// 선언만하고 구현부를 부르지 않았다면 "확인할 수 없는 외부 기호" 라는 경고문이 뜸 
            // 외부 기호가 떴다? 내가 구현 안했거나, 햇는데 오타난거임. (이런거물어보면안됨...) 

void function0()
{
}

void function1()
{
}

void function2()
{
}

