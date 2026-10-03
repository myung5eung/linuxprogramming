# 실습과제1
## 셸변수와 환경변수의 차이점을 설명하라. 
- 셸 변수: 현재 실행 중인 셸에서만 사용할 수 있는 변수, 기본적으로 자식 프로세스에는 전달되지 않음
- 환경변수: 현재 셸뿐만 아니라 해당 셸에서 실행되는 자식 프로세스에도 전달되는 변수

## 환경변수 PS1, PATH, SHELL, LANG을 출력하고 기능을 설명하라.
- PS1: 셸의 프롬프트 문자열을 설정하는 변수
- PATH: 셸이 명령어 실행파일을 찾을 디렉터리의 경로를 저장하는 변수
- SHELL: 현재 사용자의 로그인 셸 경로를 저장하는 변수
- LANG: 현재 사용하는 언어, 지역, 문자 인코딩 등의 로케일 정보를 저장하는 변수
<img width="670" height="321" alt="image" src="https://github.com/user-attachments/assets/b050454f-9be9-472f-8da3-0570faf05a19" />

## 셸이 명령어 파일의 위치를 어떻게 찾는지 설명하라.
사용자가 명령어의 이름만 입력하면 셸은 `PATH`에 등록되어 있는 디렉터리를 순서대로 검색하여 해당 명령어의 실행파일을 찾는다.

## 셸스크립트를 설명하라.
 여러 개의 셸 명령어를 하나의 파일에 작성해 놓은 것이다.

## 셸스크립트의 실행방법 3가지를 조사하라.
-  bash 명령어를 이용하여 실행
```bash
bash test.sh
```
Bash에 셸스크립트 파일을 전달하여 실행하는 방법
-  실행 권한을 부여한 후 직접 실행
먼저 실행 권한을 추가
```bash
chmod +x test.sh
```
```bash
./test.sh
```
현재 디렉터리에 있는 셸스크립트 파일을 직접 실행하는 방법
- source 명령어를 이용하여 실행
```bash
source test.sh
```

## .bashrc 파일에 환경변수 MYVER을 선언하고 값을 ubuntu 26.04으로 설정하는 코드를 추가하고 .bashrc 파일을 다시 실행(source)하라. 그리고 환경변수 MYVER의 값이 잘 설정되었는지 명령어(echo)로 확인하라
<img width="387" height="130" alt="image" src="https://github.com/user-attachments/assets/2e6c0da9-a0ca-49c2-8a58-73495b2836cd" />

<img width="437" height="82" alt="image" src="https://github.com/user-attachments/assets/e8eb3642-93e6-4432-ba3b-cf163f335ada" />

## 환경변수에 경로를 추가할 때 $ PATH=‘$PATH:~/bin’ 처럼 작성하면 어떻게 되는지 설명하라
작은따옴표 안의 `$PATH`가 기존 PATH 값으로 치환되지 않고 문자 그대로 저장되어 실제 기존 경로가 문자열이 들어가게 된다. 이렇게 사용하면 명령어 검색 경로가 사라지기 때문에 일반 명령어를 찾지 못하는 문제가 생길 수 있어 기존 PATH 값에 새로운 경로를 추가하려면 큰따옴표를 사용하여 다음과 같이 작성한다.

```bash
PATH="$PATH:~/bin"
```
