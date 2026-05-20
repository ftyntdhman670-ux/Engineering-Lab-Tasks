# الوظيفة الرابعة: تطبيقات React المتقدمة وجلب البيانات

## متطلبات التسليم
- [x] تطبيق معلومات المادة مع مصفوفة المواد ومكون Course.
### 1. كود تطبيق معلومات المادة (Course Application)
```jsx
import React from 'react'

const Part = ({ part }) => {
  return (
    <p>{part.name} {part.exercises}</p>
  )
}

const Content = ({ parts }) => {
  return (
    <div>
      {parts.map(part => <Part key={part.id} part={part} />)}
    </div>
  )
}

const Total = ({ parts }) => {
  // استخدام reduce لحساب المجموع الكلي للتمارين بشكل تصريحي
  const totalAmount = parts.reduce((sum, part) => sum + part.exercises, 0)
  
  return (
    <p><strong>Total of {totalAmount} exercises</strong></p>
  )
}

const Course = ({ course }) => {
  return (
    <div>
      <h2>{course.name}</h2>
      <Content parts={course.parts} />
      <Total parts={course.parts} />
    </div>
  )
}

const App = () => {
  const course = {
    id: 1,
    name: 'Half Stack application development',
    parts: [
      { name: 'Fundamentals of React', exercises: 10, id: 1 },
      { name: 'Using props to pass data', exercises: 7, id: 2 },
      { name: 'State of a component', exercises: 14, id: 3 },
      { name: 'Redux', exercises: 11, id: 4 }
    ]
  }

  return <Course course={course} />
}

export default App
```
- [x] تطبيق دليل الهاتف مع البحث والإضافة وجلب البيانات من json-server.
### 2. كود تطبيق دليل الهاتف (Phonebook Application)
```jsx
import React, { useState, useEffect } from 'react'
import axios from 'axios'

const App = () => {
  const [persons, setPersons] = useState([])
  const [newName, setNewName] = useState('')
  const [newNumber, setNewNumber] = useState('')
  const [filterName, setFilterName] = useState('')

  // جلب البيانات من json-server عند تحميل المكون
  useEffect(() => {
    axios
      .get('http://localhost:3001/persons')
      .then(response => {
        setPersons(response.data)
      })
  }, [])

  const addPerson = (event) => {
    event.preventDefault()
    
    // التحقق من تكرار الاسم
    if (persons.some(person => person.name.toLowerCase() === newName.toLowerCase())) {
      alert(`${newName} is already added to phonebook`)
      return
    }

    const personObject = { name: newName, number: newNumber }

    // إرسال البيانات الجديدة للسيرفر
    axios
      .post('http://localhost:3001/persons', personObject)
      .then(response => {
        setPersons(persons.concat(response.data))
        setNewName('')
        setNewNumber('')
      })
  }

  // تصفية الأسماء بناءً على قيمة البحث
  const personsToShow = filterName
    ? persons.filter(person => person.name.toLowerCase().includes(filterName.toLowerCase()))
    : persons

  return (
    <div>
      <h2>Phonebook</h2>
      <div>
        filter shown with: <input value={filterName} onChange={(e) => setFilterName(e.target.value)} />
      </div>
      
      <h3>Add a new</h3>
      <form onSubmit={addPerson}>
        <div>name: <input value={newName} onChange={(e) => setNewName(e.target.value)} /></div>
        <div>number: <input value={newNumber} onChange={(e) => setNewNumber(e.target.value)} /></div>
        <div><button type="submit">add</button></div>
      </form>
      
      <h3>Numbers</h3>
      <ul>
        {personsToShow.map(person => 
          <li key={person.name}>{person.name} {person.number}</li>
        )}
      </ul>
    </div>
  )
}

export default App
```
- [x] تمرين الدول.
### 3. كود تطبيق تمرين الدول (Countries Application)
```jsx
import React, { useState, useEffect } from 'react'
import axios from 'axios'

const App = () => {
  const [countries, setCountries] = useState([])
  const [search, setSearch] = useState('')

  // جلب بيانات جميع الدول عند تحميل المكون لأول مرة
  useEffect(() => {
    axios
      .get('[https://studies.cs.helsinki.fi/restcountries/api/all](https://studies.cs.helsinki.fi/restcountries/api/all)')
      .then(response => {
        setCountries(response.data)
      })
  }, [])

  // تصفية الدول بناءً على نص البحث
  const countriesToShow = countries.filter(country =>
    country.name.common.toLowerCase().includes(search.toLowerCase())
  )

  return (
    <div>
      <div>
        find countries <input value={search} onChange={(e) => setSearch(e.target.value)} />
      </div>

      <div style={{ marginTop: '10px' }}>
        {countriesToShow.length > 10 ? (
          <p>Too many matches, specify another filter</p>
        ) : countriesToShow.length === 1 ? (
          <div>
            <h2>{countriesToShow[0].name.common}</h2>
            <p>capital {countriesToShow[0].capital?.[0]}</p>
            <p>area {countriesToShow[0].area}</p>
            <h3>languages:</h3>
            <ul>
              {Object.values(countriesToShow[0].languages || {}).map(lang => (
                <li key={lang}>{lang}</li>
              ))}
            </ul>
            <img 
              src={countriesToShow[0].flags.png} 
              alt={`Flag of ${countriesToShow[0].name.common}`} 
              width="150" 
            />
          </div>
        ) : (
          countriesToShow.map(country => (
            <div key={country.cca3}>{country.name.common}</div>
          ))
        )}
      </div>
    </div>
  )
}

export default App
```

## أسئلة للمناقشة

1. **لماذا `reduce` أفضل من حلقة `for` لحساب المجموع في React؟**
   - لأن `reduce` طريقة تصريحية (Declarative) وتعتبر Pure Function، لا تقوم بالتعديل على متغيرات خارجية (No Mutation)، مما يجعل الكود أنظف وأكثر توافقاً مع طبيعة الـ Immutability في React.

2. **ما الفرق بين `export default` و `export`؟**
   - `export default`: لتصدير عنصر أساسي واحد فقط من الملف، وعند استيراده لا نستخدم الأقواس `{}` ويمكن تسميته بأي اسم.
   - `export`: لتصدير عدة عناصر مسمية (Named)، وعند الاستيراد يجب الالتزام بالاسم وضعه داخل أقواس متعرجة `{}`.

   3. **لماذا نضع `[]` كمعامل ثاني لـ `useEffect` عند جلب البيانات؟**
   - لضمان تنفيذ الكود **مرة واحدة فقط** عند تحميل المكون لأول مرة (Component Mount). عدم وضعها سيجعل الكود يتنفذ مع كل رندر، مما يسبب حلقة 무한ة (Infinite Loop) من الطلبات للسيرفر.

4. **ما هو المكون المتحكم به (Controlled Component) ولماذا نستخدمه؟**
   - هو المكون (مثل الـ `input`) الذي يتم تخزين قيمته والتحكم بها بالكامل عن طريق الـ `State` في React، ونستخدمه ليكون لـ React سيطرة كاملة على البيانات وتسهيل عمليات التحقق (Validation) الفورية.