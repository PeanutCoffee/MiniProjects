import React from 'react';
import { MDBFooter } from 'mdb-react-ui-kit';

export default function Footer() {
  return (
    <MDBFooter className='text-center text-lg-left'>
      <div className='text-center p-3 text-light' style={{color: '#fff'}} >
        Made with <span style={{color:'#F93154', fontSize:'19px'}}>♥</span> by{' '}
        <a className='text-light' style={{textDecoration: 'none',color: '#39C0ED'}} href='https://wilsonvd.me/'>
          Wilson VD
        </a>
      </div>
    </MDBFooter>
  );
}