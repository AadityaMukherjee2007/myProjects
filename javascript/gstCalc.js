const prompt = require("prompt-sync")();

var principal = Number(prompt("Principal amount: "))
var gstPercentage = Number(prompt("GST(%): ")) / 100
var gst = principal * gstPercentage
var TotalAmt = principal + gst

console.log("GST:", gst)
console.log("Total amount:", TotalAmt)
