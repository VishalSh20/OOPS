require('dotenv').config()
const express = require('express')
const app = express()
// console.log(express)
// console.log(typeof express)
// console.log(app)
const port = 3000
app.get('/',(req,res) => {
    res.send("Samosa")
})

app.listen(process.env.PORT,(req,res)=>{
    console.log("Eat 5 start")
})
