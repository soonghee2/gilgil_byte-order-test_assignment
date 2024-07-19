# Binary File Addition Program

이 프로그램은 두 개의 이진 파일에서 32비트 부호 없는 정수를 읽어와서 더한 후, 결과를 출력합니다.


## 컴파일 및 실행


### 실행

컴파일이 완료된 후, 프로그램을 실행하려면 다음과 같은 명령어를 사용합니다:

```sh
./add-nbo <file1> <file2>
```

여기서 `<file1>`과 `<file2>`는 32비트 부호 없는 정수가 저장된 이진 파일의 경로입니다.

#### 예시

```sh
./add-nbo five-hundred.bin thousand.bin
```

## 코드 설명

### `uint32_t plus(uint32_t n1, uint32_t n2)`

이 함수는 두 개의 `uint32_t` 정수를 받아서 그 합을 반환합니다.

### `uint32_t read_binfile_to_uint32_t(char *filename)`

이 함수는 주어진 파일 이름에서 32비트 부호 없는 정수를 읽어옵니다. 파일이 열리지 않거나 읽기 오류가 발생하면 프로그램은 에러 메시지를 출력하고 종료합니다.

### `char* write(uint32_t n)`

이 함수는 32비트 부호 없는 정수를 문자열로 변환합니다. 문자열은 정수의 10진수와 16진수 표현을 포함합니다. 메모리는 동적으로 할당되며, 호출자는 사용 후 메모리를 해제해야 합니다.

### `int main(int argc, char *argv[])`

`main` 함수는 프로그램의 엔트리 포인트입니다. 두 개의 파일 이름을 명령행 인수로 받아서 파일에서 정수를 읽고, 더한 결과를 출력합니다.

- 파일에서 정수를 읽기
- 정수 덧셈
- 문자열 변환
- 결과 출력

## 메모리 관리

- `write` 함수에서 반환된 문자열은 `main` 함수에서 `free` 함수를 호출하여 해제하였습니다.

## 오류 처리

- 파일 열기 실패
- 파일 읽기 실패
- 메모리 할당 실패

이 프로그램은 표준 오류에 적절한 에러 메시지를 출력합니다.
