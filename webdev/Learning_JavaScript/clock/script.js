function currentTime() {
  const ct = new Date();
  let h = ct.getHours();
  let m = ct.getMinutes();
  if (m < 10)
  {
    m = "0" + m;
  }
  let s = ct.getSeconds();
  if (s < 10)
  {
    s = "0" + s;
  }
  document.getElementById('time').innerHTML = h + ":" + m + ":" + s;
  setTimeout(currentTime, 1000);
}
