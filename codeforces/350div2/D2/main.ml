open Printf
open Scanf

let read_int  () = bscanf Scanning.stdib " %d "  (fun x -> x);;
let read_long () = bscanf Scanning.stdib " %Ld " (fun x -> x);;

let ( ** ) a b = Int64.mul a b
let ( ++ ) a b = Int64.add a b
let ( -- ) a b = Int64.sub a b
let ( // ) a b = Int64.div a b
let ( %% ) a b = Int64.rem a b
let ( ^^ ) a b = Int64.shift_left a b
let rec sum (i : int) (j : int) f (ac : int64) =
  if i > j then
    ac
  else
    sum (i + 1) j f (ac ++ (f i));;

let () =
  try
    while true do
      let n = read_int () in
      let k = read_long () in
      let a = Array.init n (fun _ -> read_long()) in
      let b = Array.init n (fun _ -> read_long()) in

      let possible m =
        let x = sum 0 (n - 1) (fun i -> min 4000000000L (max 0L ((m ** a.(i)) -- b.(i)))) 0L in
        x <= k
      in

      let rec binary_search small large =
        if (small ++ 1L) < large then
          let (mid : int64) = (small ++ large) // 2L in
          if possible mid then binary_search mid large else binary_search small mid
        else
          small
      in
      
      printf "%Ld\n" (binary_search 0L 2000000001L)
    done
  with End_of_file -> ()
