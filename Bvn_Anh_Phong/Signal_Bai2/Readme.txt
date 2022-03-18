                /*********************** SIGNAL BÀI 2 ***********************/

    Đề bài: Realtime signal và standard signal là gì? Phân biệt sự khác nhau giữa chúng.


                /*********************** ĐÁP ÁN BÀI 2 ***********************/
    
    Linux hỗ trợ các tín hiệu standard signal. --> Là các signal ta đã học có giá trị từ 0-31
        --> Nếu các tín hiệu standard signal đang được chờ xử lí, thì process sẽ không biết phải xử lí theo thứ tự hay cụ thể là signal nào. 

    Với Realtime signal sẽ cho các tín hiệu signal nhận được vào queue và xử lí sau đó theo thứ tự trong queue.