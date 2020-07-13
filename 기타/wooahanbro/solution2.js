var words = [1, 2, 3, 1, 2, 3, 4];

//count the total number of anagram sets in an array of strings. Capital and lowercase chars are considered identical
function solution2(arr) {
    var anagramCount = {};
    var answer = 0;
    for (var i in arr) {
        arr[i] = String(arr[i]);
    }
    for (var i in arr) {
        arr[i] = arr[i].split("").sort().join("").toLowerCase();
    }
    //count all duplicate array values
    arr.forEach(function(x) {
        anagramCount[x] = (anagramCount[x] || 0) + 1;
    });

    for (var j in anagramCount) {
        if (anagramCount[j] >= 1) {
            answer++;
        }
    }
    return answer;
}
console.log(solution2(words));

/*

문제 설명

애너그램(Anagram)이란 주어진 단어를 이루는 문자의 위치를 뒤바꾸어 새로운 단어를 만드는 것을 말합니다. 예를 들어 listen의 문자 위치만 바꾸면 silent가 되며 두 단어를 애너그램이라고 부릅니다.

이는 숫자에도 적용할 수 있는데, 예를 들어 1814와 1481은 애너그램입니다. 1814의 각 자릿수 위치를 바꾸어 1481을 만들 수 있기 때문입니다.

자연수가 담긴 배열이 주어질 때, 애너그램 관계인 숫자들끼리 묶어서 그룹을 만들려합니다. 예를 들어 배열에 담긴 숫자가 [112, 1814, 121, 1481, 1184]이라면 [112, 121]이 한 그룹이 되며, [1814, 1481, 1184]가 한 그룹이 됩니다. 각 숫자들은 같은 그룹에 속하는 다른 모든 숫자들과 애너그램 관계입니다.

자연수가 담긴 배열 arr가 매개변수로 주어질 때, 애너그램 관계인 숫자들끼리 묶어서 그룹을 만들면 총 몇 그룹이 만들어지는지 return 하도록 solution 함수를 완성해주세요.
제한사항

    arr의 길이는 1 이상 100,000 이하입니다.
    arr의 원소는 1 이상 1,000,000 이하입니다.

입출력 예
arr 	result
[112, 1814, 121, 1481, 1184] 	2
[123, 456, 789, 321, 654, 987] 	3
[1, 2, 3, 1, 2, 3, 4] 	4
[123, 234, 213, 432, 234, 1234, 2341, 12345, 324] 	4
입출력 예 설명

입출력 예 #1

다음과 같이 두 그룹이 있습니다.

    [112, 121]
    [1814, 1481, 1184]

입출력 예 #2

다음과 같이 세 그룹이 있습니다.

    [123, 321]
    [456, 654]
    [789, 987]

입출력 예 #3

다음과 같이 네 그룹이 있습니다.

    [1, 1]
    [2, 2]
    [3, 3]
    [4]

입출력 예 #4

다음과 같이 네 그룹이 있습니다.

    [123, 213]
    [234, 432, 234, 324]
    [1234, 2341]
    [12345]


*/