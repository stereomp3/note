a xor k xor k = a

用一次xor是加密，再用相同的key xor一次就可以解開

很多加密是用很多鑰匙和很多xor 和 xor中間加上位移去做加密

密碼需要保護seed和演算法，現在比較注重保護seed(初始值)

SSS injection、SQL injection 如果資料庫或網站沒有寫好，就很容易被攻擊



fail2ban可以擋掉一些外部攻擊 --> 暴力攻擊

helmet 可以擋掉各式各樣的東西，可以啟用裡面的防護措施，讓安全性提高



整數的因數分解是密碼學裡面很重要的一塊

質數在密碼學很重要 因為RSA的出現(public key, private key)

https://zh.wikipedia.org/wiki/RSA%E5%8A%A0%E5%AF%86%E6%BC%94%E7%AE%97%E6%B3%95

mod是%

使擴展歐幾里得算法的等效公式算法

```tsx
// 參考 -- https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
// gcd(a,b) = ri = a*si+b*ti
// gcd(e,N) =  1 = e*si+N*ti
//             1 = e*si mod N  => si=d 是 e 的 modInverse
export function extEuclid(a: bigint, b: bigint) {
  let [si, s] = [1n, 0n] // let si = 1n, s = 0n // let [si,s] = [1n,0n]
  let [ti, t] = [0n, 1n] // let ti = 0n, t = 1n // let [ti,t] = [0n,1n]
  let [ri, r] = [a, b] // let ri = a, r = b   // let [ri,r] = [a,b]
  if (b === 0n)
    return [1n, 0n, a]
  else {
    while (r != 0n) {
      let q = ri / r
      let rt = r; r = ri - q * rt; ri = rt; // [ri, r] = [r, ri-q*r]
      let st = s; s = si - q * st; si = st; // [si, s] = [s, si-q*s]
      let tt = t; t = ti - q * tt; ti = tt; // [ti, t] = [t, ti-q*t]
    }
  }
  return [si, ti, ri]
}xxxxxxxxxx // gcd(a,b) = ri = si+b*tiexport function extEuclid(a: bigint, b: bigint) {  let [si, s] = [1n, 0n] // let si = 1n, s = 0n // let [si,s] = [1n,0n]  let [ti, t] = [0n, 1n] // let ti = 0n, t = 1n // let [ti,t] = [0n,1n]  let [ri, r] = [a, b] // let ri = a, r = b   // let [ri,r] = [a,b]  if (b === 0n)    return [1n, 0n, a]  else {    while (r != 0n) {      let q = ri / r      let rt = r; r = ri - q * rt; ri = rt; // [ri, r] = [r, ri-q*r]      let st = s; s = si - q * st; si = st; // [si, s] = [s, si-q*s]      let tt = t; t = ti - q * tt; ti = tt; // [ti, t] = [t, ti-q*t]    }  }  return [si, ti, ri]}// 參考 -- https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm// gcd(a,b) = ri = a*si+b*ti// gcd(e,N) =  1 = e*si+N*ti//             1 = e*si mod N  => si=d 是 e 的 modInverseexport function extEuclid(a: bigint, b: bigint) {  let [si, s] = [1n, 0n] // let si = 1n, s = 0n // let [si,s] = [1n,0n]  let [ti, t] = [0n, 1n] // let ti = 0n, t = 1n // let [ti,t] = [0n,1n]  let [ri, r] = [a, b] // let ri = a, r = b   // let [ri,r] = [a,b]  if (b === 0n)    return [1n, 0n, a]  else {    while (r != 0n) {      let q = ri / r      let rt = r; r = ri - q * rt; ri = rt; // [ri, r] = [r, ri-q*r]      let st = s; s = si - q * st; si = st; // [si, s] = [s, si-q*s]      let tt = t; t = ti - q * tt; ti = tt; // [ti, t] = [t, ti-q*t]    }  }  return [si, ti, ri]}
```



求出 modInverse

n





加解密實作

```js
// const NodeRSA = require('node-rsa');
import RSA from "https://dev.jspm.io/node-rsa"

// const key = new RSA({b: 2048});
const keyPem = await Deno.readTextFile("./private.pem")
const key = new RSA(keyPem);
const plaintext = 'pay John => Mary $100';
console.log('plaintext: ', plaintext);
const encrypted = key.encrypt(plaintext, 'base64');
console.log('encrypted: ', encrypted);
const decrypted = key.decrypt(encrypted, 'utf8');
console.log('decrypted: ', decrypted);

const signature = key.sign(plaintext)

const pubPem = await Deno.readTextFile("./public.pem")
const pubKey = new RSA(pubPem);

console.log('signature=', signature)

// const isVerified = key.verify(plaintext, signature)
const isVerified = pubKey.verify(plaintext, signature)
console.log('isVerified=', isVerified)


const isVerified2 = pubKey.verify(plaintext+'a', signature)
console.log('isVerified2=', isVerified2)

signature[0] = signature[0]+1
const isVerified3 = pubKey.verify(plaintext, signature)
console.log('isVerified3=', isVerified3)
```



```ts
export function genKeyPair() {
  let p = B.randomPrime(keySize), q=B.randomPrime(keySize)
  let N = p*q, r=(p-1n)*(q-1n)
  let e = B.randomPrime(keySize) // e<r
  console.log('e=', e)
  console.log('r=', r)
  let d = B.modInv(e, r) // ed=1 mod r, d 如何找？ 找一個 k 使(k*r+1)%e == 0
  // 要用 modInverse 函數，參考 https://github.com/rzcoder/node-rsa/blob/master/src/libs/jsbn.js
  // 該算法又參考了書 -- https://cacr.uwaterloo.ca/hac/about/chap14.pdf 14.4.3 Binary extended gcd algorithm
  // 其中的 14.61 Algorithm Binary extended gcd algorithm
  console.log('e*d mod r=', (e*d)%r)
  return {e,d,N}  // e N 是public key， d N 是private key
}
```

數學難題 :  黎曼猜想