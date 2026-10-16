# 실습과제 1

## 프로그램 개발과정 편집 → 선행처리 → 컴파일 → 링크 → 실행 단계를 자세히 설명하시오.

- **편집**: C언어로 컴퓨터가 처리할 작업을 기술하여 소스코드로 작성하는 단계이다.
- **선행처리**: 컴파일 전에 수행되며 헤더 파일 포함, 매크로 치환, 조건부 컴파일 등을 통해 소스코드를 컴파일 가능한 형태로 처리하는 단계이다.
- **컴파일**: 전처리된 소스코드를 분석하여 기계어에 가까운 목적파일로 번역하는 단계이다.
- **링크**: 여러 개의 목적파일과 라이브러리를 결합하여 함수와 변수의 참조를 해결하고 실행파일을 생성하는 단계이다.
- **실행**: 생성된 실행파일을 실제로 실행하는 단계이다.

## 프로젝트 빌드 후 소스파일(c), 목적파일(obj), 실행파일(exe)의 위치를 찾아보라.

프로젝트를 빌드한 후 파일 탐색기를 이용하여 다음 파일의 위치를 확인하고 검색 결과 화면을 첨부한다.

- 소스파일: `.c`
- 목적파일: `.obj`
- 실행파일: `.exe`


# 실습과제 2

## 매크로 상수를 사용한 예제를 실행해보고 소스코드를 자세히 설명하라.

```c
#include <stdio.h>

#define AGE 22
#define NAME "Resister_boy"
#define WEIGHT 90

int main() {
    printf("My Age is %d\n", AGE);
    printf("My Name is %s\n", NAME);
    printf("My Weight is %d\n", WEIGHT);

    return 0;
}
```

- `#include <stdio.h>`: `printf()` 함수를 사용하기 위해 표준 입출력 헤더 파일을 포함한다.
- `#define AGE 22`: `AGE`라는 매크로 상수를 정의하며 전처리 과정에서 `AGE`가 `22`로 치환된다.
- `#define NAME "Resister_boy"`: `NAME`이라는 매크로 상수를 정의하며 전처리 과정에서 문자열로 치환된다.
- `#define WEIGHT 90`: `WEIGHT`라는 매크로 상수를 정의하며 전처리 과정에서 `90`으로 치환된다.
- `printf("My Age is %d\n", AGE);`: `AGE`의 값인 `22`를 출력한다.
- `printf("My Name is %s\n", NAME);`: `NAME`의 문자열 값을 출력한다.
- `printf("My Weight is %d\n", WEIGHT);`: `WEIGHT`의 값인 `90`을 출력한다.
- `return 0;`: 프로그램을 정상적으로 종료한다.


# 실습과제 3

## `#if ~ #elif ~ #endif` 지시자를 사용하는 이유를 설명하라.

`#if`, `#elif`, `#else`, `#endif`는 조건에 따라 특정 코드를 컴파일에 포함하거나 제외하기 위해 사용하는 조건부 컴파일 지시자이다.  
디버그 설정, 기능 선택, 시스템 환경에 따른 코드 분리 등에 사용할 수 있다.

## `#if ~ #elif ~ #endif` 지시자를 사용한 예제를 실행해보고 소스코드를 자세히 설명하라.

```c
#include <stdio.h>

#define DLEVEL 6
#define STACKUSE 1

void display(int* ptr) {
    printf("debugptr 값: %d\n", *ptr);
}

int main() {

    int debugval = 999;
    int* debugptr = &debugval;

#if DLEVEL > 5

#define SIGNAL 1

#if STACKUSE == 1
#define STACK 200
#else
#define STACK 100
#endif

#else

#define SIGNAL 0

#if STACKUSE == 1
#define STACK 100
#else
#define STACK 50
#endif

#endif

#if DLEVEL == 0

#undef STACK
#define STACK 0

#elif DLEVEL == 1

#undef STACK
#define STACK 100

#elif DLEVEL > 5

    display(debugptr);

#else

#undef STACK
#define STACK 200

#endif

    printf("SIGNAL: %d\n", SIGNAL);
    printf("STACK: %d\n", STACK);

    return 0;
}
```

- `#define DLEVEL 6`: 디버그 레벨을 의미하는 매크로 상수이다.
- `#define STACKUSE 1`: 스택 사용 여부를 나타내는 매크로 상수이다.
- `display()` 함수는 포인터가 가리키는 값을 출력한다.
- `#if DLEVEL > 5`: `DLEVEL`이 5보다 큰지 검사한다.
- `#define SIGNAL 1`: 조건이 참이면 `SIGNAL`을 1로 정의한다.
- `#if STACKUSE == 1`: 스택 사용 여부를 검사한다.
- `#define STACK 200`: `DLEVEL > 5`이고 `STACKUSE == 1`이면 `STACK`을 200으로 정의한다.
- `#else`: 앞의 조건이 거짓일 경우 실행될 전처리 영역이다.
- `#undef STACK`: 기존에 정의된 `STACK` 매크로를 제거한다.
- `#elif`: 앞의 조건이 거짓일 때 새로운 조건을 검사한다.
- `#elif DLEVEL > 5`: `DLEVEL`이 5보다 크면 `display(debugptr)` 코드가 컴파일에 포함된다.
- 최종적으로 `SIGNAL`과 `STACK`의 값을 출력한다.


# 실습과제 4

## `#ifdef ~ #endif` 지시자를 사용하는 이유를 설명하라.

`#ifdef`는 특정 매크로가 정의되어 있는 경우에만 해당 코드를 컴파일하기 위해 사용하는 조건부 컴파일 지시자이다.  
주로 디버그 코드나 특정 기능의 사용 여부를 선택할 때 사용한다.

## `#ifdef ~ #endif` 지시자를 사용한 예제를 실행해보고 소스코드를 자세히 설명하라.

```c
#include <stdio.h>

#define DEBUG

int main()
{
#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    return 0;
}
```

- `#include <stdio.h>`: `printf()` 함수를 사용하기 위해 표준 입출력 헤더 파일을 포함한다.
- `#define DEBUG`: `DEBUG` 매크로를 정의한다.
- `#ifdef DEBUG`: `DEBUG` 매크로가 정의되어 있는지 확인한다.
- `printf(...)`: `DEBUG`가 정의되어 있기 때문에 해당 코드가 컴파일에 포함된다.
- `__DATE__`: 컴파일한 날짜를 나타낸다.
- `__TIME__`: 컴파일한 시간을 나타낸다.
- `__FILE__`: 현재 소스파일의 이름을 나타낸다.
- `__LINE__`: 현재 코드의 줄 번호를 나타낸다.
- `#endif`: 조건부 컴파일 영역을 종료한다.


# 실습과제 5

## `#ifndef ~ #endif` 지시자를 사용하는 이유를 설명하라.

`#ifndef`는 특정 매크로가 정의되어 있지 않을 경우에만 해당 코드를 컴파일하기 위해 사용하는 조건부 컴파일 지시자이다.  
주로 헤더 파일의 중복 포함을 방지하거나 특정 매크로가 없을 때만 기능을 실행하도록 할 때 사용한다.

## `#ifndef ~ #endif` 지시자를 사용한 예제를 실행해보고 소스코드를 자세히 설명하라.

```c
#include <stdio.h>

#ifndef DEBUG
#define DEBUG
#endif

int main()
{
#ifndef TEST
    printf("TEST 매크로가 정의되어 있지 않습니다.\n");
#endif

    return 0;
}
```

- `#include <stdio.h>`: `printf()` 함수를 사용하기 위해 표준 입출력 헤더 파일을 포함한다.
- `#ifndef DEBUG`: `DEBUG` 매크로가 정의되어 있지 않은지 검사한다.
- `#define DEBUG`: `DEBUG`가 정의되어 있지 않다면 새롭게 정의한다.
- `#endif`: `#ifndef DEBUG` 조건부 컴파일 영역을 종료한다.
- `#ifndef TEST`: `TEST` 매크로가 정의되어 있지 않은지 검사한다.
- `printf(...)`: `TEST`가 정의되어 있지 않으므로 해당 코드가 컴파일에 포함되어 문장이 출력된다.
- 마지막 `#endif`: 조건부 컴파일 영역을 종료한다.
