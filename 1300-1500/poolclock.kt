fun solve(k: Long, m: Long): Long {
    return maxOf(0L, 2 * k - (m % (3 * k)))
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (k, m) = readLine()!!.split(" ").map { it.toLong() }
        println(solve(k, m))
    }
}
