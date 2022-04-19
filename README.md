# 42cursus_03_Philosophers

## 사용법
* ./philo
1. number_of_philosophers
2. time_to_die 
3. time_to_eat
4. time_to_sleep
5. [number_of_times_each_philosopher_must_eat]

## Mandatory
* mutex
  - 여러 스레드가 공유자원에 접근하는 것을 막음.

* 동적 뮤텍스
  - 동적뮤텍스 초기화 : pthread_mutex_init
  - 실행 중에 뮤텍스를 할당하여 사용하고자 할 때 이용
  - 동적으로 할당한 뮤텍스는 pthread_mutex_destroy를 이용하여 해제해줘야 한다.

* pthread_create
  - 스레드 생성함수
  - 인자: 스레드 식별자, 스레드 특성, 실행할 스레드 함수, 스레드 함수에 넘겨질 매개변수

* pthread_join
  - 모든 스레드가 종료될 때까지 기다린다
  - 인자: 스레드 식별자, 넘겨받을 리턴값

* 철학자 문제에서 중요한 것
  - 데드락을 방지하는 것
  - 방법 1. 짝수 번째는 왼쪽부터, 홀수 번째는 오른쪽부터 포크를 집게 한다. https://m.blog.naver.com/hirit808/221788147057

## Bonus
* 프로세스와 스레드 차이
  - 프로세스 내에서 실행되는 흐름의 단위가 스레드.
  - 스레드는 stack만 따로 할당받고 code, data, heap 영역을 공유하기 때문에 공통 자원에 접근 가능함. 업데이트 된 메모리에도 똑같이 접근 가능.
  - 프로세스는 stack, code, data, heap 영역 모두 독립된 존재. 업데이트 된 메모리 접근 불가능.

* semaphore
  - 여러 프로세스가 공유자원에 접근하는 것을 막음.

* mutex와 semaphore 차이
  - 뮤텍스는 프로세스 단에서 관리되기 때문에 다른 프로세스에서 접근은 하지 못 함. 뮤텍스 변수를 가지고 있는 프로세스 안에서 접근 가능.
  - 세마포어는 스레드나 프로세스에서 모두 접근 가능
