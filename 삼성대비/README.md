# 삼성전자 SW 역량테스트 대비

## 기본자료 1. 바킹독
- [유튜브](https://youtu.be/LcOIobH7ues?si=H38RqHtxx6ggNgWI)
- [블로그](https://blog.encrypted.gg/921)

> 기본자료는 바킹독을 참고. 1주일 남았으므로, 코드트리나 백준에 있는 기출문제를 풀 예정.

## 삼성전자 SW 역량테스트 합격 전략
- [링크](https://www.codetree.ai/blog/%EC%82%BC%EC%84%B1-sw-%EC%97%AD%EB%9F%89%ED%85%8C%EC%8A%A4%ED%8A%B8-%EC%A4%80%EB%B9%84-%EC%8B%A4%EC%A0%84-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4%EB%B6%80%ED%84%B0-%ED%95%A9%EA%B2%A9-%EC%A0%84%EB%9E%B5/)
- [실제 후기](https://flik.tistory.com/38) / [실제 후기2](https://garden1500.tistory.com/8) / [실제 후기 3](https://vivivic98.tistory.com/42)
- visual studio를 이용할 경우 - 파일 입출력
  - (1) [리소스파일에 새파일 추가](https://zoosso.tistory.com/930) (freopen(), #define _crt_secure_no_warnings)
  - (2) [디버깅창](https://zoosso.tistory.com/926) (입력: <, 출력: >)
  - (3) 리소스파일에 기존 파일 추가하는 방법 찾자 (추적이 안되는데 왠지 모르겠다..?)

### 문제 풀이 전략
1. 시간 분배 (4시간 2문제)
    - 이상적인 시간: 문제 읽는 시간 20분 / 로직 필기하는 시간 20분 / 실제 구현 시간 40분 / 디버깅, 테스트 시간 20분
      (20m + 20m + 40m + 20m = 1h 40m)
    - 두 문제 모두 읽고, 자신 있는 문제 먼저 풀자 -> 1솔 목표
2. DFS 보다는 BFS
    - BFS로 풀이 먼저 생각하고, 도저히 안 되면 DFS로 빠지기 (BFS가 더 유리함)
3. 전역변수 초기화
    - 전역 변수 초기화 필수 (memset 등)
    - 문제 풀이할 때, 마지막 테스트 케이스를 가장 먼저 앞에 배치. 마지막 케이스가 일반적으로 배열의 크기가 크므로 초기화가 잘 되는지 확인하기 위함.
4. 루틴
   - 도구 -> 옵션 -> 일반 (어둡게)
   - 도구 -> 옵션 -> 키보드 (vscode)
