# Audio Multiplexer 기능 C++11 구현

- 기대효과 :
  - 기존에는 loop-sleep 을 사용.
    - sleep 시간이 길면 반응성이 늦고 Video Data와의 Sync가 깨짐
    - sleep 시간이 짧으면 시스템 부하가 발생
    - sleep 시간 최적화를 위해 많은 시간 투자가 필요하며 신규 SoC 도입할때마다 최적화 수행해야함
  - c++11의 condition_variable 사용하여 반응성을 높이고 불필요한 최적화 수행을 하지 않도록 함
  - c++11의 lock_guard 를 사용하여 RAII 의 이점을 활용하도록 함
- 주의사항
  - Producer Consumer Pattern 정확하게 사용할것
  - conditiona_variable 의 signal lose 조심

## Audio Multiplexer


```
               +---------+             
               | Player  |--------+     
               +---------+        |                      
+----------+   +---------+        |        +---------+   +---------+   +---------+ 
| Producer |---| Encoder |-+------+------+-| Decoder |---| Play    |-+-| Analog  |
+----------+   +---------+ |             | +---------+   +---------+ | +---------+
                           |             |                           |            
                           | +---------+ | +---------+               | +---------+
                           +-| Record  | +-| Remote  |               +-| HDMI    |
                             +---------+   +---------+                 +---------+

```

### Producer
- SDK 로부터 Audio Raw Packet 을 받음
  AudioData 객체 생성하는 것으로 대체
  33ms 당 하나씩 생성
- Encoder Queue 에 Enqueue

### Encoder
- G.726 으로 Encoding 
- Storage, Decoder, Remote Queue 에 Enqueue

### Decoder
- Encoder/Storage 에서 온 AudioData 를 Dequeue하여 Raw Packet으로 Decoding 후 Play

### Storage
- Encoder 에서 온 AudioData를 Storage에 Write
- Storage에서 읽어온 AudioData를 Decoder, Remote Queue 에 Enqueue

## 구현 계획
- 기존 기능을 c++ 11 로 구현
- Unittest 로  gtest 도입

