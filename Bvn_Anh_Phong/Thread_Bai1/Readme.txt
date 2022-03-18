                      /*********************** THREAD BÀI 4 ***********************/

    Đề bài: Viết một chương trình để chứng minh rằng các thread khác nhau trong cùng một process có thể có các tập 
hợp signal đang chờ xử lý (set of pending signal) khác nhau,được trả về bằng sigpending(). Bạn có thể làm điều này bằng 
cách sử dụng pthread_kill() để gửi các tín hiệu khác nhau đến hai thread khác nhau đã bị block các tín hiệu này, và sau 
với mỗi thread gọi sigpending() hãy hiển thị thông tin về các tín hiệu đang chờ xử lý.

                        /*********************** ĐÁP ÁN BÀI 4 ***********************/
