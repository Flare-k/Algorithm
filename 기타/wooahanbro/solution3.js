//reqs = ["DEPOSIT 3a 10000", "CREATE 3a 300000", "WITHDRAW 3a 150000", "WITHDRAW 3a 150001"];
reqs = ["CREATE 3a 10000", "CREATE 3a 20000", "CREATE 2bw 30000"];

function solution3(reqs) {
    var member = {
        user: "",
        account: 0,
    };
    var answer = [];

    for (var i = 0; i < reqs.length; i++) {
        var res = reqs[i].split(" ");
        if (res[0] === "DEPOSIT") {
            if (member.user != undefined || member.user != res[0]) {
                answer.push(404);
            } else if (member.user == res[1]) {
                member.account += (res[2] - '0');
                answer.push(200);
            }
        } else if (res[0] == "CREATE") {
            if (member.user == res[1]) {
                answer.push(403);
            } else {
                member.user = res[1];
                member.account = -1 * (res[2] - '0');
                answer.push(200);
            }
        } else if (res[0] == "WITHDRAW") {
            if (member.user == res[1]) {
                if (member.account + (res[2] - '0') > 0) {
                    answer.push(403);
                } else {
                    member.account += (res[2] - '0');
                    answer.push(200);
                }
            } else {
                answer.push(404);
            }
        }
    }

    console.log(member);
    return answer;
}

console.log(solution3(reqs));

/*

문제 설명

계좌 개설, 입금, 출금을 처리하는 은행 서버를 구현하려 합니다. 은행 서버는 들어온 요청을 처리한 후, 요청을 처리한 방법에 따라 상태 코드를 보내주어야 합니다. 서버에 들어오는 요청과 보낼 상태 코드는 다음과 같습니다.

    계좌 개설 요청: CREATE 계좌아이디 최대한도
        이미 개설된 계좌라면 403 코드를 보냅니다.
        개설되지 않은 계좌라면 -최대한도까지 출금할 수 있는 계좌를 개설한 후, 200 코드를 보냅니다.
    입금 요청: DEPOSIT 계좌아이디 금액
        없는 계좌라면 404 코드를 보냅니다.
        있는 계좌라면 금액 만큼을 입금한 후 200 코드를 보냅니다.
    출금 요청: WITHDRAW 계좌아이디 금액
        없는 계좌라면 404 코드를 보냅니다.
        계좌가 있지만, 최대한도를 초과한다면 출금을 하지 않고 403 코드를 보냅니다.
        그 외의 경우 계좌에서 금액 만큼을 출금 후 200 코드를 보냅니다.

이때 서버로 들어온 요청에 대해 각각 어떤 코드를 보내야 하는지 알아보려 합니다. 예를 들어 다음과 같은 요청이 들어왔습니다.

DEPOSIT 3a 10000
CREATE 3a 300000
WITHDRAW 3a 150000
WITHDRAW 3a 150001

위 요청은 다음과 같이 처리합니다.
들어온 요청 	처리 결과 	3a번 계좌 상태
DEPOSIT 3a 10000 	3a번 계좌가 없으므로 404 코드를 보냅니다. 	아직 계좌가 없음
CREATE 3a 300000 	최대한도가 -300,000원인 계좌를 개설합니다. 200 코드를 보냅니다. 	계좌가 생성됨. 잔액 0원
WITHDRAW 3a 150000 	3a번 계좌에서 150,000원을 출금합니다. 200 코드를 보냅니다. 	잔액 -150,000원
WITHDRAW 3a 150001 	3a번 계좌의 최대한도를 초과하는 요청이므로 403 코드를 보냅니다. 	잔액 -150,000원

따라서 이때에는 각 요청에 대해 [404, 200, 200, 403] 코드를 보내야 합니다.

서버로 들어온 요청을 담은 배열 reqs가 주어질 때 각 요청에 대해 어떤 코드를 보내야 하는지 return 하도록 solution 함수를 작성해주세요.
제한 사항

    reqs의 길이는 1 이상 100,000 이하입니다.
    reqs의 원소는 명령어 계좌아이디 숫자 형식입니다.
        명령어는 CREATE, DEPOSIT, WITHDRAW 중 하나입니다.
        계좌아이디는 영문 소문자와 숫자로 구성된, 길이 1 이상 30 이하인 문자열입니다.
        숫자는 1 이상 1,000,000 이하인 자연수입니다.

입출력 예
reqs 	result
["DEPOSIT 3a 10000", "CREATE 3a 300000", "WITHDRAW 3a 150000", "WITHDRAW 3a 150001"] 	[404, 200, 200, 403]
["CREATE 3a 10000", "CREATE 3a 20000", "CREATE 2bw 30000"] 	[200, 403, 200]
입출력 예 설명

입출력 예 #1

앞서 설명한 예와 같습니다.

입출력 예 #2
들어온 요청 	처리 결과
CREATE 3a 10000 	-10,000 만큼 출금할 수 있는 계좌를 개설합니다. 200 코드를 보냅니다.
CREATE 3a 20000 	이미 3a번 계좌가 있으므로 403 코드를 보냅니다.
CREATE 2bw 30000 	-30,000 만큼 출금할 수 있는 계좌를 개설합니다. 200 코드를 보냅니다.

따라서 [200, 403, 200]을 리턴해야 합니다.

*/