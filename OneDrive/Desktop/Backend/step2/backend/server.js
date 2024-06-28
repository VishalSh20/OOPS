import express from 'express'
const app = express()

app.get('/',(req,res)=>{
    res.send('Server is ready')
})

const port = 4000;
app.listen(port,(req,res)=>{
    console.log("Listening at localhost:4000")
})