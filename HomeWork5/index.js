const express = require('express');
const app = express();
const PORT = 3001;

// مفسر البيانات لقراءة الـ JSON
app.use(express.json());

// مصفوفة البيانات المبدئية لدليل الهاتف
let persons = [
  { id: 1, name: "Arto Hellas", number: "040-123456" },
  { id: 2, name: "Ada Lovelace", number: "39-44-5323523" },
  { id: 3, name: "Dan Abramov", number: "12-43-234345" },
  { id: 4, name: "Mary Poppendieck", number: "39-23-6423122" }
];

// مسار مبدئي للتأكد من عمل السيرفر
app.get('/', (request, response) => {
    response.send('<h1>مرحباً بك في سيرفر دليل الهاتف!</h1>');
});

// 1. جلب جميع الأسماء (GET ALL)
app.get('/api/persons', (request, response) => {
  response.json(persons);
});

// 2. جلب اسم واحد محدد بواسطة الـ id
app.get('/api/persons/:id', (request, response) => {
  const id = Number(request.params.id); 
  const person = persons.find(p => p.id === id); 

  if (person) {
    response.json(person);
  } else {
    response.status(404).send({ error: 'Person not found' }); 
  }
});

// 3. حذف اسم محدد بواسطة الـ id
app.delete('/api/persons/:id', (request, response) => {
  const id = Number(request.params.id);
  persons = persons.filter(p => p.id !== id); 

  response.status(204).end(); 
});

// 4. إضافة اسم جديد (POST)
app.post('/api/persons', (request, response) => {
  const body = request.body;

  if (!body.name || !body.number) {
    return response.status(400).json({ error: 'name or number is missing' });
  }

  const nameExists = persons.some(p => p.name === body.name);
  if (nameExists) {
    return response.status(400).json({ error: 'name must be unique' });
  }

  const newPerson = {
    id: Math.floor(Math.random() * 10000),
    name: body.name,
    number: body.number
  };

  persons = persons.concat(newPerson);
  response.json(newPerson);
});

// 5. مسار معلومات دليل الهاتف (info) -> هاد يلي كان ناقص!
app.get('/info', (request, response) => {
  const entriesCount = persons.length;
  const date = new Date();
  response.send(`<p>Phonebook has info for ${entriesCount} people</p><p>${date}</p>`);
});

// تشغيل السيرفر (دائماً آخر سطر بالملف)
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});