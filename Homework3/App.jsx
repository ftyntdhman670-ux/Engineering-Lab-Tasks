import React from 'react';

// 1. مكون الرأس (Header)
const Header = (props) => <h1>{props.course}</h1>;

// 2. مكون الجزء (Part) ليكون الكود منظماً جداً
const Part = (props) => (
  <p>{props.part} {props.exercises}</p>
);

// 3. مكون المحتوى (Content) الذي يمرر البيانات للأجزاء
const Content = (props) => (
  <div>
    <Part part={props.parts[0].name} exercises={props.parts[0].exercises} />
    <Part part={props.parts[1].name} exercises={props.parts[1].exercises} />
    <Part part={props.parts[2].name} exercises={props.parts[2].exercises} />
  </div>
);

// 4. مكون المجموع (Total)
const Total = (props) => {
  const sum = props.parts[0].exercises + props.parts[1].exercises + props.parts[2].exercises;
  return <p><b>Number of exercises {sum}</b></p>;
};

// 5. التمرين الإضافي: بطاقة الطالب (Student Card)
const StudentCard = ({ name, id, major }) => (
  <div style={{ border: '2px solid #61dafb', padding: '15px', marginTop: '20px', borderRadius: '10px', width: 'fit-content' }}>
    <h2 style={{ margin: '0' }}>Student Card</h2>
    <p>Name: {name}</p>
    <p>ID: {id}</p>
    <p>Major: {major}</p>
  </div>
);

// المكون الأساسي الذي يجمع كل شيء
const App = () => {
  const course = 'Half Stack application development';
  const parts = [
    { name: 'Fundamentals of React', exercises: 10 },
    { name: 'Using props to pass data', exercises: 7 },
    { name: 'State of a component', exercises: 14 }
  ];

  return (
    <div style={{ fontFamily: 'Arial, sans-serif', padding: '20px' }}>
      <Header course={course} />
      <Content parts={parts} />
      <Total parts={parts} />
      
      {/* هنا نضع بياناتك لمرة واحدة */}
      <StudentCard name="Fatina" id="2026-CS-001" major="Informatics Engineering" />
    </div>
  );
};

export default App;