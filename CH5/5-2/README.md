# 실습과제 1
<img width="487" height="335" alt="image" src="https://github.com/user-attachments/assets/1e330fa6-223b-42dd-ad97-f923ef511e17" />

# 실습과제 2
<img width="667" height="470" alt="image" src="https://github.com/user-attachments/assets/834cfe00-3ce7-4c88-8cd5-d799cb56421c" />

<img width="660" height="620" alt="image" src="https://github.com/user-attachments/assets/b7daf9ef-21b7-4a17-afff-54df6944b271" />

<img width="647" height="695" alt="image" src="https://github.com/user-attachments/assets/e5e22c8d-022f-4f92-a05b-529040a63a44" />

# 실습과제 3
<img width="265" height="326" alt="image" src="https://github.com/user-attachments/assets/83a101e2-782e-4f28-916d-58244a576f85" />

<img width="457" height="367" alt="image" src="https://github.com/user-attachments/assets/6df8fe97-f12a-4c46-be38-bc3b594274b7" />

<img width="737" height="532" alt="image" src="https://github.com/user-attachments/assets/426b370b-95a0-4788-a6dd-94f1855857e7" />

# 실습과제 4
- 하드링크와 심볼릭 링크의 차이를 설명하라. <br>
하드링크는 하나의 실제 파일에 여러 개의 파일 이름을 연결하는 방식이다. 하드링크로 만들어진 파일들은 같은 실제 데이터를 가리키기 때문에 구분하기 어렵고, 하나의 하드링크 이름을 삭제하더라도 다른 하드링크가 남아 있으면 실제 파일 데이터는 삭제되지 않는다.
심볼릭 링크는 원본 파일의 경로 정보를 저장하고 있는 별도의 특수 파일로 원본 파일과 구분된다. 심볼릭 링크를 삭제해도 원본 파일에는 영향을 주지 않지만, 원본 파일이 삭제되면 심볼릭 링크는 연결이 끊어진 상태가 된다.
- 심볼릭 링크를 확인하는 명령어를 설명하라.<br>
ls -l
- -빈파일과 빈디렉토리를 만든 후 파일속성(ls -l)을 출력하면 아래처럼 디렉터리는 하드링크의 수가 2이고 파일은 1이다. 이유를 설명하라.<br>
일반 파일을 처음 만들면 그 파일을 가리키는 이름이 하나이므로 하드링크의 수가 1로 표시되는데, 디렉터리는 생성될 때 자동으로 .(현재 디렉터리 자신을 가리키는 하드링크)과 관련된 링크 구조를 가지기 때문에 기본 하드링크의 수가 2로 표시된다. 

<img width="717" height="241" alt="image" src="https://github.com/user-attachments/assets/55f02462-d2d9-4609-93a0-7c06f3a68a60" />
