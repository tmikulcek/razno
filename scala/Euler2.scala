object EvenFibb {
  val fibb: Stream[Int] = 0 #:: fibb.scanLeft(1)(_ + _)

  def main (args: Array[String]) {
    println(fibb.takeWhile(_ <= 4000000).toList.filter(_ % 2 == 0).sum)
  }
}
