from std import io.*
from std import random.*

/*
* 游戏菜单
*/
func menu(): Int64 {
    println()
    println("请输入选项前数字以开始，以回车键结束输入！")
    println("1.开始游戏            2.游戏规则(建议阅读)")
    println("3.作者信息            4.版本说明")

    var read = Console.readln().getOrThrow()
    var c = read[0]
    println()
    match(c) {
        case '1' =>
            game()
        case '2' =>
            println("游戏规则:")
            println("1.系统会随机产生4个不同的数（数从0-9中选择）。")
            println("2.根据系统提示，您有10次机会推理出这四个数是什么。")
            println("3.当您输入4个数后，系统会以*A*B的格式提示您。")
            println("4.*代表个数，A代表数字和位置均正确，B代表数字正确但位置不正确。")
            println("示例：假设随机数为2803，您猜测0123，系统会提示您1A2B。")
            menu()
        case '3' =>
            println("作者信息:")
            println("Wingrez")
            menu()
        case '4' =>
            println("版本说明:")
            println("The first cangjie program")
            menu()
        case _ =>
            game()
    }
    return 0
}

/*
* 返回四个随机数
*/
func fourRandomNumber(): Array<Int64> {
    let arr = [0, 0, 0, 0]
    let r: Random = Random()
    while (true) {
        for (i in 0..4) {
            arr[i] = Int64(r.nextUInt8(10))
        }
        if (arr[0] != arr[1] && arr[0] != arr[2] && arr[0] != arr[3] &&
            arr[1] != arr[2] && arr[1] != arr[3] &&
            arr[2] != arr[3]) {
                break
            }
    }
    return arr
}

/*
* 判断输入是否合法
*/
func isInputValid(s: String): Bool {
    if (s.size != 5) {
        return false
    }

    for (i in 0..4) {
        if (s[i] < '0' || s[i] > '9') {
            return false
        }
        for (j in (i + 1)..4) {
            if (s[i] == s[j]) {
                return false
            }
        }
    }

    return true
}

/*
* 游戏判定
*/
func game(): Int64 {
    var expect = fourRandomNumber()

    println("游戏现在开始！")
    println("请在输入4位不同的数字后，以回车键结束输入！\n")

    for (q in 0..10){
        var A = 0
        var B = 0
        var inputError = false

        print("第${q + 1}次机会\t\t>> ")
        var read = Console.readln().getOrThrow()

        if (!isInputValid(read)){
            println("请输入4位不同的数字！\t  [错误]")
            continue
        } else {
            for (i in 0..4){
                var input = Int64(UInt32(read[i]) - UInt32('0'))
                if (input == expect[i]) {
                    A++
                }
                for (j in 0..4){
                    if (input == expect[j] && i != j) {
                        B++
                    }
                }
            }
        }

        println("\t\t\t  [${A}A${B}B]")
        println("--------------------------------")
        if (A == 4){
            println("恭喜您猜对了！您共用了${q + 1}次机会！")
            return 0
        }
    }

    println("很遗憾！您的机会用完了！");
    println("正确答案是${expect[0]}${expect[1]}${expect[2]}${expect[3]}")
    return 0
}

main() {
    println("4A0B--猜数字小游戏")
    menu()
    println("再见！欢迎下次再玩！")
}