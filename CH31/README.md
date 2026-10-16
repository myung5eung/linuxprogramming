# 실습과제 1

프로그램 개발과정 편집 → 선행처리 → 컴파일 → 링크 → 실행 단계를 자세히 설명하시오.

- 편집: C언어로 컴퓨터가 처리할 작업을 기술하여 소스코드로 작성하는 단계이다.
- 선행처리: 컴파일 전에 수행되며 헤더파일을 포함하거나 매크로를 치환하고 조건에 따라 일부 코드를 포함 또는 제외하는 단계이다.
- 컴파일: 선행처리가 끝난 소스코드를 기계어로 변환하여 목적파일을 생성하는 단계이다.
- 링크: 목적파일과 라이브러리를 연결하여 하나의 실행파일을 생성하는 단계이다.
- 실행: 생성된 실행파일을 메모리에 불러와 실제로 프로그램을 실행하는 단계이다.

프로젝트 빌드 후 소스파일(c), 목적파일(obj), 실행파일(exe)의 위치를 찾아보라.

- 소스파일: `.c`
- 목적파일: `.obj`
- 실행파일: `.exe`

파일 탐색기에서 각 파일의 위치를 검색하고 결과 화면을 첨부한다.


# 실습과제 2

매크로 상수를 사용한 예제를 인터넷에서 찾아서 실행해보고 소스코드를 자세히 설명하라.

매크로 상수는 숫자나 문자열 등을 의미 있는 이름으로 정의하여 사용하는 것으로 소스코드의 가독성을 높이고 수정하기 쉽게 해준다. 선행처리 과정에서 매크로 이름은 정의된 값으로 치환된다.

```c
#include <stdio.h>              // printf 함수를 사용하기 위한 헤더파일

#define AGE 22                 // AGE를 22로 정의
#define NAME "Resister_boy"    // NAME을 문자열 "Resister_boy"로 정의
#define WEIGHT 90              // WEIGHT를 90으로 정의

int main() {
    printf("My Age is %d\n", AGE);       // AGE가 22로 치환되어 출력
    printf("My Name is %s\n", NAME);     // NAME이 "Resister_boy"로 치환되어 출력
    printf("My Weight is %d\n", WEIGHT); // WEIGHT가 90으로 치환되어 출력

    return 0;                           // 프로그램 정상 종료
}
```


# 실습과제 3

`#if ~ #elif ~ #endif` 지시자를 사용하는 이유를 설명하라.

`#if`, `#elif`, `#else`, `#endif`는 조건에 따라 소스코드의 일부를 컴파일에 포함하거나 제외하기 위해 사용한다. 일반적인 `if`문은 프로그램 실행 중 조건을 판단하지만, `#if`는 선행처리 단계에서 컴파일할 코드를 결정한다.

```c
#include <stdio.h>

#define DLEVEL 6       // 디버그 레벨을 6으로 정의
#define STACKUSE 1     // 스택 사용 여부를 1로 정의

void display(int* ptr) {
    printf("debugptr 값: %d\n", *ptr);   // 포인터가 가리키는 값을 출력
}

int main() {

    int debugval = 999;          // 디버그용 값
    int* debugptr = &debugval;   // debugval의 주소 저장

#if DLEVEL > 5                   // DLEVEL이 5보다 큰 경우

#define SIGNAL 1                 // SIGNAL을 1로 정의

#if STACKUSE == 1                // STACKUSE가 1인 경우
#define STACK 200                // STACK을 200으로 정의
#else
#define STACK 100                // STACKUSE가 1이 아니면 STACK을 100으로 정의
#endif

#else                            // DLEVEL이 5보다 크지 않은 경우

#define SIGNAL 0                 // SIGNAL을 0으로 정의

#if STACKUSE == 1
#define STACK 100                // STACKUSE가 1이면 STACK을 100으로 정의
#else
#define STACK 50                 // STACKUSE가 1이 아니면 STACK을 50으로 정의
#endif

#endif

#if DLEVEL == 0                  // DLEVEL이 0인 경우

#undef STACK                     // 기존 STACK 정의 제거
#define STACK 0                  // STACK을 0으로 다시 정의

#elif DLEVEL == 1                // DLEVEL이 1인 경우

#undef STACK
#define STACK 100                // STACK을 100으로 다시 정의

#elif DLEVEL > 5                 // DLEVEL이 5보다 큰 경우

    display(debugptr);           // display 함수를 실행할 코드가 컴파일에 포함됨

#else                            // 위 조건에 모두 해당하지 않는 경우

#undef STACK
#define STACK 200                // STACK을 200으로 다시 정의

#endif

    printf("SIGNAL: %d\n", SIGNAL);   // 최종 SIGNAL 값 출력
    printf("STACK: %d\n", STACK);     // 최종 STACK 값 출력

    return 0;
}
```


# 실습과제 4

`#ifdef ~ #endif` 지시자를 사용하는 이유를 설명하라.

`#ifdef`는 지정한 매크로가 정의되어 있을 경우에만 해당 코드를 컴파일에 포함하기 위해 사용한다. 매크로의 값보다 매크로가 정의되어 있는지 여부가 중요하다.

```c
#include <stdio.h>

#define DEBUG    // DEBUG 매크로 정의

int main()
{
#ifdef DEBUG     // DEBUG가 정의되어 있으면 아래 문장을 컴파일에 포함
    printf("Debug: %s %s %s %d\n",
        __DATE__,   // 컴파일한 날짜
        __TIME__,   // 컴파일한 시간
        __FILE__,   // 현재 소스파일 이름
        __LINE__);  // 현재 코드의 줄 번호
#endif             // 조건부 컴파일 종료

    return 0;
}
```


# 실습과제 5

`#ifndef ~ #endif` 지시자를 사용하는 이유를 설명하라.

`#ifndef`는 지정한 매크로가 정의되어 있지 않을 경우에만 해당 코드를 컴파일에 포함하기 위해 사용한다. 헤더파일이 여러 번 포함되는 것을 방지할 때에도 주로 사용한다.

```c
#include <stdio.h>

#define MIN     // MIN 매크로는 정의하고 ADD 매크로는 정의하지 않음

int main(void)
{
    int num1 = 10;
    int num2 = 20;

#ifndef ADD     // ADD가 정의되어 있지 않으므로 아래 문장을 컴파일에 포함
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
#endif

#ifndef MIN     // MIN은 이미 정의되어 있으므로 아래 문장은 컴파일에서 제외
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
#endif

    return 0;
}
```
