# 실습과제 1
프로그램 개발과정 편집->선행처리->컴파일->링크->실행 단계를 자세히 설명하시오.
프로젝트 빌드 후 소스파일(c), 목적파일(obj), 실행파일(exe)의 위치를찾아보라->파일 탐색기 검색 화면을 첨부할 것
- 편집: c언어로 컴퓨터가 처리할 작업을 기술하여 소스코드로 작성하는 단계이다.
- 선행처리: 컴파일 전에 수행되며  파일 확장,  매크로 치환, 조건부 컴파일 등을 통해 소스코드를 컴파일 가능한 형태로 변환하는 단계이다.
- 컴파일: 전처리된 소스코드를 분석과정을 거쳐 기계어에 가까운 목적파일로 번역하는 단계이다.
- 링크: 여러 개의 목적파일과 라이브러리를 결합하여 함수와 변수의 참조를 해결하고 문제없는 실행파일을 생성하는 단계이다.
- 실행:  프로그램을 실행하는 단계

# 실습과제 2
매크로 상수를 사용한 예제를 인터넷에서 찾아서 실행해보고 소스코드를 자세히 설명하라

```
#define AGE 22 
#define NAME "Resister_boy"
#define WEIGHT 90

int main() {
	printf("My Age is %d\n", AGE); // AGE는 전처리 과정에서 22로 치환
	printf("My Name is %s\n", NAME); // NAME은 전처리 과정에서 Resister_boy로 치환
	printf("My Weight is %d\n", WEIGHT); // WEIGHT은 전처리 과정에서 90으로 치환
	return (0);
}
```

# 실습과제 3
#if ~#elif~ #endif 지시자를 사용하는 이유를 설명하라.
#if ~#elif~ #endif 지시자를 사용한 예제를 인터넷에서 찾아서 실행해보고 소스코드를 자세히 설명하라.

```
#include <stdio.h>   // printf 함수를 사용하기 위해 포함

// 조건부 컴파일에 사용할 매크로 값 설정
#define DLEVEL 6     // 디버그 레벨을 의미함, 5보다 크면 디버그 수준이 높은 상태로 봄
#define STACKUSE 1   // 스택 사용 여부를 의미함, 1이면 스택을 사용한다고 봄

// DLEVEL이 5보다 클 때 실행될 display 함수
void display(int* ptr) {
    printf("debugptr 값: %d\n", *ptr);   // 포인터가 가리키는 값을 출력
}

int main() {

    int debugval = 999;          // 디버그용 값
    int* debugptr = &debugval;   // debugval의 주소를 저장하는 포인터

    // DLEVEL이 5보다 큰지 검사
#if DLEVEL > 5

#define SIGNAL 1             // DLEVEL이 5보다 크면 SIGNAL을 1로 정의

// STACKUSE가 1인지 검사
#if STACKUSE == 1
#define STACK 200        // DLEVEL > 5 이고 STACKUSE == 1이면 STACK은 200
#else
#define STACK 100        // DLEVEL > 5 이고 STACKUSE != 1이면 STACK은 100
#endif

#else

#define SIGNAL 0             // DLEVEL이 5 이하이면 SIGNAL을 0으로 정의

// STACKUSE가 1인지 검사
#if STACKUSE == 1
#define STACK 100        // DLEVEL <= 5 이고 STACKUSE == 1이면 STACK은 100
#else
#define STACK 50         // DLEVEL <= 5 이고 STACKUSE != 1이면 STACK은 50
#endif

#endif

    // DLEVEL 값에 따라 다시 조건을 검사
#if DLEVEL == 0

#undef STACK                 // 앞에서 정의된 STACK을 지움
#define STACK 0              // DLEVEL이 0이면 STACK을 0으로 다시 정의

#elif DLEVEL == 1

#undef STACK                 // 앞에서 정의된 STACK을 지움
#define STACK 100            // DLEVEL이 1이면 STACK을 100으로 다시 정의

#elif DLEVEL > 5

    display(debugptr);           // DLEVEL이 5보다 크면 이 코드가 컴파일에 포함됨

#else

#undef STACK                 // 앞에서 정의된 STACK을 지움
#define STACK 200            // 위 조건들이 모두 아니면 STACK을 200으로 다시 정의

#endif

    // 최종적으로 결정된 매크로 값 출력
    printf("SIGNAL: %d\n", SIGNAL);   // SIGNAL 값 출력
    printf("STACK: %d\n", STACK);     // STACK 값 출력

    return 0;                         // 프로그램 정상 종료
}
```

# 실습과제 4
#ifdef ~ #endif 지시자를 사용하는 이유를 설명하라.
#ifdef ~ #endif 지시자를 사용한 예제를 인터넷에서 찾아서 실행해보고소스코드를자세히설명하라.

```
#include <stdio.h>

#define DEBUG    // DEBUG 매크로 정의

int main()
{
#ifdef DEBUG     // DEBUG 매크로가 정의되어 있다면 아래 코드를 컴파일함
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    return 0;
}
```

# 실습과제 5
#ifndef ~ #endif 지시자를 사용하는 이유를 설명하라.
#ifndef ~ #endif 지시자를 사용한 예제를 인터넷에서 찾아서 실행해보고소스코드를자세히설명하라.

```
#include <stdio.h>

#define DEBUG    // DEBUG 매크로 정의

int main()
{
#ifdef DEBUG     // DEBUG 매크로가 정의되어 있다면 아래 코드를 컴파일함
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    return 0;
}
```

